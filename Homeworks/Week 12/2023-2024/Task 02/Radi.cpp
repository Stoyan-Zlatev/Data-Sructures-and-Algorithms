#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Vertex
{
    size_t from;
    size_t to;
    int64_t gain;
    size_t cost;
    size_t index;

    bool operator<(const Vertex &other) const
    {
        return cost == other.cost ? gain > other.gain : cost < other.cost;
    }
};

const size_t MAX = 2e5 + 2;
Vertex edges[MAX];
size_t parent[MAX];
size_t depht[MAX];

size_t findParent(size_t v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v]);
}

void unionVert(size_t from, size_t to)
{
    if (depht[from] < depht[to])
    {
        parent[from] = to;
    }
    else
    {
        parent[to] = from;
        if (depht[from] == depht[to])
        {
            depht[from]++;
        }
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].gain;
        edges[i].index = i + 1;
    }

    sort(edges, edges + M, less<Vertex>());

    for (size_t i = 0; i <= N; i++)
    {
        parent[i] = i;
        depht[i] = 0;
    }

    size_t vertex1, vertex2;
    for (size_t i = 0; i < M; i++)
    {
        vertex1 = findParent(edges[i].from);
        vertex2 = findParent(edges[i].to);
        // if there is no cycle
        if (vertex2 != vertex1)
        {
            cout << edges[i].index << '\n';
            unionVert(vertex1, vertex2);
        }
    }
    return 0;
}
