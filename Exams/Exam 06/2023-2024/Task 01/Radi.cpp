#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    size_t v;
    size_t u;
};

Edge edges[1000002];

size_t parent[100002];
size_t depht[100002];

size_t findParent(size_t v)
{
    if (v == parent[v])
    {
        return v;
    }
    return findParent(parent[v]);
}

void unionV(size_t v, size_t u)
{
    if (depht[v] < depht[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        if (depht[v] == depht[u])
        {
            depht[v]++;
        }
    }
}

int main()
{
    size_t N, x, y, M = 0;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        parent[i] = i;
        depht[i] = 0;
    }
    while (cin >> x >> y)
    {
        edges[M] = {x, y};
        M++;
    }

    size_t components = N;
    for (size_t i = 0; i < M; i++)
    {
        size_t parentV = findParent(edges[i].v);
        size_t parentU = findParent(edges[i].u);
        if (parentV != parentU)
        {
            components--;
            cout << components << '\n';
            unionV(parentV, parentU);
            continue;
        }
        cout << components << " CYCLE FORMED!" << '\n';
    }

    return 0;
}
