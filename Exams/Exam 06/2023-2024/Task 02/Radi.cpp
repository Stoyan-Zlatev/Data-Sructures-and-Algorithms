#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

unordered_map<size_t, vector<size_t>> g[1000002];
pair<size_t, size_t> dist[1000002];
size_t N, M, x, y, w;

void dijkstra(size_t v)
{
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    pq.push({0, v});

    while (!pq.empty())
    {
        size_t currentV = pq.top().second;
        size_t currentCost = pq.top().first;
        pq.pop();

        if (currentCost > dist[currentV].first)
            continue;

        for (auto &n : g[currentV])
        {
            size_t child = n.first;

            for (size_t i = 0; i < n.second.size(); i++)
            {
                size_t childCost = n.second[i];

                if (dist[child].first > dist[currentV].first + childCost)
                {
                    dist[child].first = dist[currentV].first + childCost;
                    dist[child].second = dist[currentV].second;

                    pq.push({dist[currentV].first + childCost, child});
                }
                else if (dist[child].first == dist[currentV].first + childCost)
                {
                    dist[child].second = (dist[child].second + dist[currentV].second) % 1000000007;
                }
            }
        }
    }
}

int main()
{

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        g[x][y].push_back(w);
    }
    for (size_t i = 2; i <= N; i++)
    {
        dist[i] = {LONG_MAX, 0};
    }
    dist[1] = {0, 1};
    dijkstra(1);

    if (dist[N].first != LONG_MAX)
    {
        cout << dist[N].first << " " << dist[N].second;
    }
    else
    {
        cout << "-1 0";
    }

    return 0;
}
