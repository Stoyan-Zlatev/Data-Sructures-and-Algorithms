#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

const size_t MAX = 1e6 + 20;

unordered_map<size_t, vector<pair<size_t, size_t>>> g[MAX];

size_t dist[MAX];

size_t startV;
size_t endV;
size_t maxTime;

bool dijkstra(size_t maxW)
{
    size_t end = endV;
    size_t start = startV;
    for (size_t i = start; i <= end; i++)
    {
        dist[i] = -1;
    }

    dist[start] = 0;
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;

    pq.push({0, start});
    while (!pq.empty())
    {
        size_t currentT = pq.top().first;
        size_t currentVertex = pq.top().second;
        pq.pop();

        for (auto &ns : g[currentVertex])
        {
            size_t childVertex = ns.first;

            for (auto &n : ns.second)
            {
                size_t childW = n.first;
                size_t childT = n.second;

                if (childW > maxW)
                    continue;

                if (dist[childVertex] > currentT + childT)
                {
                    dist[childVertex] = currentT + childT;
                    pq.push({dist[childVertex], childVertex});
                }
            }
        }
    }

    return dist[end] <= maxTime;
}

int binary(int lowerBound, int upperBound)
{
    int mid;
    bool first = true;
    while (lowerBound <= upperBound)
    {
        mid = lowerBound + (upperBound - lowerBound) / 2;
        if (dijkstra(mid))
        {
            upperBound = mid - 1;
        }
        else
        {
            if (first)
                return -1;
            lowerBound = mid + 1;
        }

        first = false;

        if (lowerBound == -2147483648)
            return -1;
    }

    return lowerBound;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t junctionsCount, tunnelsCount, batteryLife;
    cin >> junctionsCount >> tunnelsCount >> batteryLife;
    size_t junction1, junction2, weight, time;

    for (size_t i = 0; i < tunnelsCount; i++)
    {
        cin >> junction1 >> junction2 >> weight >> time;
        g[junction1][junction2].push_back({weight, time});
    }

    startV = 1;
    endV = junctionsCount;
    maxTime = batteryLife;

    cout << binary(1, INT_MAX);

    return 0;
}
