#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct Node
{
    size_t x;
    size_t y;
    int64_t cost;
    int64_t gain;
    size_t index;

    bool operator<(const Node &other) const
    {
        return cost == other.cost ? gain > other.gain : cost < other.cost;
    }
};

const size_t MAX_SIZE = 2e5 + 5;
Node edges[MAX_SIZE];
size_t parents[MAX_SIZE];

size_t findVert(size_t v)
{
    if (v == parents[v])
        return v;

    return parents[v] = findVert(parents[v]);
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
            std::cout << edges[i].index << '\n';
            unionVert(first, second);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    for (size_t i = 0; i < m; i++)
    {
        std::cin >> edges[i].x >> edges[i].y >> edges[i].cost >> edges[i].gain;
        edges[i].index = i + 1;
    }

    kruskal(n, m);

    return 0;
}