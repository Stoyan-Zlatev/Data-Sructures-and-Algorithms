
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Group
{
    size_t arrival;
    size_t departure;
    size_t people;

    bool operator<(const Group &other) const
    {
        return arrival > other.arrival;
    }

    bool operator>(const Group &other) const
    {
        return departure > other.departure;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        size_t arrival, departure, people, N, C;
        cin >> N >> C;

        priority_queue<Group, vector<Group>, less<Group>> arrivals;
        for (size_t j = 0; j < N; j++)
        {
            cin >> people >> arrival >> departure;
            arrivals.push({arrival, departure, people});
        }

        priority_queue<Group, vector<Group>, greater<Group>> departures;
        size_t currentCount = 0;
        bool canSeat = true;
        while (!arrivals.empty())
        {
            while (!departures.empty() && departures.top().departure <= arrivals.top().arrival)
            {
                currentCount -= departures.top().people;
                departures.pop();
            }

            currentCount += arrivals.top().people;
            departures.push(arrivals.top());
            arrivals.pop();

            if (currentCount > C)
            {
                canSeat = false;
                break;
            }
        }
        cout << canSeat << endl;
    }

    return 0;
}