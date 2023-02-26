#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    size_t x;
    size_t y;
    int64_t cost;

    bool operator<(const Node &other) const
    {
        return cost == other.cost ? x < other.x : cost < other.cost;
    }
};

const size_t MAX_SIZE = 2e5 + 5;
Node edges[MAX_SIZE];
size_t parents[MAX_SIZE];

size_t findVert(size_t v)
{
    return v == parents[v] ? v : parents[v] = findVert(parents[v]);
}

void unionVert(size_t from, size_t to)
{
    parents[from] = parents[to];
}

void kruskal(size_t n, size_t m)
{
    std::sort(edges, edges + m, std::less<Node>());

    for (size_t i = 0; i <= n; i++)
    {
        parents[i] = i;
    }

    size_t first, second;
    for (size_t i = 0; i < m; i++)
    {
        first = findVert(edges[i].x);
        second = findVert(edges[i].y);
        if (first != second)
        {
            unionVert(first, second);
        }
    }
}

int main()
{

    size_t n, m;
    std::cin >> n >> m;

    for (size_t i = 0; i < m; i++)
    {
        std::cin >> edges[i].x >> edges[i].y >> edges[i].cost;
    }

    kruskal(n, m);

    return 0;
}