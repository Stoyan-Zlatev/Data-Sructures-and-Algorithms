#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<pair<size_t, size_t>> edges;
size_t parents[(size_t)1e5 + 2];

size_t findVert(size_t vert)
{
    if (vert == parents[vert])
        return vert;

    return parents[vert] = findVert(parents[vert]);
}

size_t kruskal(size_t n, size_t m)
{
    size_t count = 0;
    for (size_t i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    size_t first, second;
    for (size_t i = 0; i < m; i++)
    {
        first = findVert(edges[i].first);
        second = findVert(edges[i].second);

        if (first != second)
        {
            count++;
            parents[first] = parents[second];
        }
    }

    return count;
}

int main()
{
    size_t P;
    cin >> P;

    for (size_t i = 0; i < P; i++)
    {
        size_t N, M, K, L;
        cin >> N >> M >> K >> L;

        edges.clear();

        size_t x, y;
        for (size_t j = 0; j < M; j++)
        {
            cin >> x >> y;
            edges.push_back({x, y});
        }

        if (K >= L)
        {
            size_t roads = kruskal(N, M);

            unordered_set<size_t> discos;
            for (size_t j = 1; j <= N; j++)
            {
                discos.insert(findVert(parents[j]));
            }

            cout << (L * roads + discos.size() * K) << endl;
        }
        else
        {
            cout << N * K << endl;
        }
    }
    return 0;
}
