#include <iostream>
#include <algorithm>
#include <unordered_map>

std::unordered_map<size_t, std::vector<size_t>> g;

bool visited[101]{};
size_t toRemove = 0;

size_t disjoin(size_t root)
{
    visited[root] = true;
    size_t totalCount = 1;
    for (auto &iter : g[root])
    {
        if (!visited[iter])
        {
            size_t count = disjoin(iter);
            if (count > 0 && count % 2 == 0)
                toRemove++;
            else
                totalCount += count;
        }
    }

    return totalCount;
}

int main()
{

    size_t v, e;
    std::cin >> v >> e;

    size_t x, y;

    for (size_t i = 1; i <= e; i++)
    {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    disjoin(1);
    std::cout << toRemove;

    return 0;
}