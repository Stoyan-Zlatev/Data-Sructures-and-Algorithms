#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>

const size_t MAX_SIZE = 1e4 + 1;
size_t times[MAX_SIZE];
size_t distances[MAX_SIZE];

std::unordered_map<size_t, std::unordered_map<size_t, size_t>> g;

int dijkstra(size_t V, size_t s, size_t e)
{
    for (size_t i = 0; i < V; i++)
    {
        distances[i] = INT_MAX;
    }

    distances[s] = 0;

    std::set<std::pair<size_t, size_t>> pq;

    pq.insert({0, s});

    while (!pq.empty())
    {

        auto current = *pq.begin();
        pq.erase(current);

        if (current.second == e)
        {
            return distances[current.second];
        }

        for (auto &x : g[current.second])
        {
            size_t upToRound = current.first % times[current.second];
            size_t newTime = current.first + x.second;

            if (upToRound != 0)
            {
                newTime += (times[current.second] - upToRound);
            }

            if (distances[x.first] > newTime)
            {
                pq.erase({distances[x.first], x.first});
                distances[x.first] = newTime;
                pq.insert({distances[x.first], x.first});
            }
        }
    }

    return -1;
}

int main()
{

    size_t V, E, s, e;
    std::cin >> V >> E >> s >> e;

    for (size_t i = 0; i < V; i++)
    {
        std::cin >> times[i];
    }

    size_t x, y, z;
    for (size_t i = 0; i < E; i++)
    {
        std::cin >> x >> y >> z;

        if (g[x][y] == 0)
        {
            g[x][y] = INT_MAX;
        }

        g[x][y] = std::min(z, g[x][y]);
    }

    std::cout << dijkstra(V, s, e);

    return 0;
}
