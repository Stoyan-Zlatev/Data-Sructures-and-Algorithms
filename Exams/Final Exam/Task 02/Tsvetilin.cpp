#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

const size_t MAX_SIZE = 1e7 + 1;
size_t comp = 0;
size_t conn[MAX_SIZE]{};

std::unordered_map<size_t, size_t> groupsSize;

void dfs(std::vector<size_t> g[], size_t root)
{
    if (conn[root] != 0)
        return;

    conn[root] = comp;
    groupsSize[comp]++;

    for (auto &iter : g[root])
        dfs(g, iter);
}

int main()
{

    size_t n, m, k;
    std::cin >> n >> m >> k;
    std::vector<size_t> g[MAX_SIZE];

    size_t x, y;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (conn[i] == 0)
        {
            comp++;
            dfs(g, i);
        }
    }

    size_t count = 0;
    for (auto &iter : groupsSize)
        if (iter.second % k == 0)
            ++count;

    std::cout << count;

    return 0;
}
