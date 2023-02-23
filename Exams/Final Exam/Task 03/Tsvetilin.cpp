#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct record
{
    long long arrive;
    long long leave;
    long long index;
    long long chair = -1;

    bool operator<(const record &other) const
    {
        return arrive > other.arrive;
    }

    bool operator>(const record &other) const
    {
        return leave > other.leave;
    }
};

int main()
{

    std::priority_queue<record, std::vector<record>, std::less<record>> orderedByArrive;
    std::priority_queue<record, std::vector<record>, std::greater<record>> orderedByLeave;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> freeChairs;

    int n;
    std::cin >> n;
    for (long long i = 0; i <= n + 5; ++i)
        freeChairs.push(i);

    long long a, l;
    for (long long i = 0; i < n; i++)
    {
        std::cin >> a >> l;
        orderedByArrive.push({a, l, i});
    }

    long long t;
    std::cin >> t;

    long long end = -1;
    long long currentChair = -1;
    while (true)
    {
        if (orderedByArrive.empty() && orderedByLeave.empty())
            break;

        while (!orderedByLeave.empty() && orderedByLeave.top().leave <= end)
        {
            std::cout << "remove " << orderedByLeave.top().index << std::endl;
            freeChairs.push(orderedByLeave.top().chair);
            orderedByLeave.pop();
        }

        if (orderedByArrive.empty())
            break;

        record curRecord = orderedByArrive.top();
        long long index = curRecord.index;
        end = curRecord.arrive;

        while (!orderedByLeave.empty() && orderedByLeave.top().leave <= end)
        {
            freeChairs.push(orderedByLeave.top().chair);
            orderedByLeave.pop();
        }

        curRecord.chair = freeChairs.top();
        currentChair = curRecord.chair;
        freeChairs.pop();

        orderedByLeave.push(curRecord);
        orderedByArrive.pop();

        if (index == t)
        {
            std::cout << currentChair;
            break;
        }
    }

    return 0;
}