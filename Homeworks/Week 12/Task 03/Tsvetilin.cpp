#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

struct Node
{
    size_t x;
    size_t y;
    size_t s;

    bool operator<(const Node &other) const
    {
        return s < other.s;
    }
};

const size_t MAX_SIZE = 1e4 + 5;
Node edges[MAX_SIZE];
size_t parents[MAX_SIZE];

size_t findVert(size_t v)
{
    if (v == parents[v])
        return v;

    return parents[v] = findVert(parents[v]);
}

bool unionVert(size_t from, size_t to)
{
    size_t u = findVert(from);
    size_t v = findVert(to);

    parents[v] = u;
    return u != v;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    size_t f, t, s;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> f >> t >> s;
        edges[i] = {f, t, s};
    }

    std::sort(edges, edges + m, std::less<Node>());

    size_t minV = 0;
    size_t maxV = ULLONG_MAX;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j <= n; j++)
        {
            parents[j] = j;
        }

        size_t count = 0;
        size_t currentMin = edges[i].s;
        size_t currentMax = edges[i].s;
        size_t diff = maxV - minV;
        for (size_t j = i; j < m; j++)
        {
            if (unionVert(edges[j].x, edges[j].y))
            {
                count++;
                currentMax = std::max(currentMax, edges[j].s);
            }

            if (diff <= currentMax - currentMin)
                break;
        }

        if (count != n - 1 || diff <= currentMax - currentMin)
            continue;

        minV = currentMin;
        maxV = currentMax;
    }

    std::cout << minV << " " << maxV;

    return 0;
}
