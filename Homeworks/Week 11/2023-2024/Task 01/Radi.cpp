#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const size_t MAX_SIZE = 1e4 + 2;
size_t times[MAX_SIZE];
size_t dist[MAX_SIZE];

unordered_map<size_t, size_t> g[MAX_SIZE];

long long dijkstra(size_t V, size_t start, size_t end)
{
    for (size_t i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        size_t currentVertex = pq.top().second;
        size_t currentCost = pq.top().first;
        pq.pop();

        if (currentVertex == end)
        {
            return dist[currentVertex];
        }

        for (auto &x : g[currentVertex])
        {
            size_t neededTimeToWait = currentCost % times[currentVertex];
            size_t newTime = currentCost + x.second;

            if (neededTimeToWait != 0)
            {
                newTime += (times[currentVertex] - neededTimeToWait);
            }

            if (dist[x.first] > newTime)
            {
                dist[x.first] = newTime;
                pq.push({dist[x.first], x.first});
            }
        }
    }

    return -1;
}

int main()
{

    size_t V, E, s, e;
    cin >> V >> E >> s >> e;

    for (size_t i = 0; i < V; i++)
    {
        cin >> times[i];
    }

    size_t x, y, cost;
    for (size_t i = 0; i < E; i++)
    {
        cin >> x >> y >> cost;

        if (g[x][y] == 0)
        {
            g[x][y] = INT_MAX;
        }

        g[x][y] = min(cost, g[x][y]);
    }

    cout << dijkstra(V, s, e);

    return 0;
}