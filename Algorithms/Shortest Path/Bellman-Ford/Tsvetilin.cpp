#include <vector>
#include <climits>
#include <iostream>

struct Edge
{
    long long x, y, cost;
};

std::vector<Edge> edges;

void bellmanFord(size_t start, size_t n, size_t m)
{
    std::vector<int64_t> dist(n + 1, INT64_MAX);
    dist[start] = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (dist[edges[j].x] != INT64_MAX && dist[edges[j].x] + edges[j].cost < dist[edges[j].y])
            {
                dist[edges[j].y] = dist[edges[j].x] + edges[j].cost;
            }
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        if (dist[edges[i].x] != INT64_MAX && dist[edges[i].x] + edges[i].cost < dist[edges[i].y])
        {
            std::cout << "Negative weight cycle detected!" << std::endl;
            return;
        }
    }
}