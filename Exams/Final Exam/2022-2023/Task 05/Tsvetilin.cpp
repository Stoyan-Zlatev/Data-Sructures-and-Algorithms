#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>

std::unordered_map<size_t, int> bestItem;
std::unordered_map<int, size_t> itemCounter;

int main()
{
    size_t n;
    std::cin >> n;

    std::queue<std::pair<size_t, size_t>> q; // id - time
    std::set<size_t> times;
    size_t maxTime = 0;

    size_t x, y;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> x >> y;
        q.push({x, y});
        times.insert(y);
        maxTime = std::max(y, maxTime);
    }

    long long maxPair = 0;
    long long maxId = -1;
    while (!q.empty())
    {
        size_t currentId = q.front().first;
        itemCounter[currentId]++;
        if (itemCounter[currentId] >= maxPair)
        {
            maxPair = itemCounter[currentId];
            maxId = currentId;
        }

        bestItem[q.front().second] = maxId;
        q.pop();
    }

    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        std::cin >> x;
        if (x >= maxTime)
        {
            std::cout << bestItem[maxTime] << '\n';
            continue;
        }

        auto tempTime = times.lower_bound(x);
        if (x < *tempTime)
        {
            if (tempTime == times.begin())
            {
                std::cout << -1 << '\n';
                continue;
            }
            x = *(--tempTime);
        }
        else
        {
            x = *tempTime;
        }

        std::cout << bestItem[x] << '\n';
    }

    return 0;
}