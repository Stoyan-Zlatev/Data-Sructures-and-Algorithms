#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>
#include <queue>
using namespace std;

typedef long long llong;
typedef std::pair<llong, llong> lpair;

const llong MAX_SIZE = 401;

llong distances[MAX_SIZE][MAX_SIZE];
std::vector<lpair> adjacencyList[MAX_SIZE];

void dijkstra(llong V, llong s)
{
    for (int i = 0; i < V; i++)
        distances[s][i] = LLONG_MAX;

    distances[s][s] = 0;

    std::priority_queue<lpair, std::vector<lpair>, std::greater<lpair>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        llong current = pq.top().second;
        llong costToCurrent = pq.top().first;
        pq.pop();

        if (costToCurrent > distances[s][current])
            continue;

        for (auto &neighbour : adjacencyList[current])
        {
            llong child = neighbour.first;
            llong newCost = costToCurrent + neighbour.second;

            if (distances[s][child] > newCost)
            {
                distances[s][child] = newCost;
                pq.push({newCost, child});
            }
        }
    }
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    llong V, E, Q;
    std::cin >> V >> E >> Q;

    llong x, y, z;
    for (long long i = 0; i < E; i++)
    {
        std::cin >> x >> y >> z;
        adjacencyList[x].push_back({y, z});
    }

    std::vector<lpair> queries(Q);
    std::unordered_set<llong> starts;
    for (llong i = 0; i < Q; i++)
    {
        std::cin >> queries[i].first >> queries[i].second;
        starts.insert(queries[i].first);
    }

    for (auto iter = starts.begin(); iter != starts.end(); iter++)
    {
        dijkstra(V, *iter);
    }

    for (llong i = 0; i < Q; i++)
    {
        if (distances[queries[i].first][queries[i].second] == LLONG_MAX)
            std::cout << -1 << "\n";
        else
            std::cout << distances[queries[i].first][queries[i].second] << '\n';
    }

    return 0;
}
