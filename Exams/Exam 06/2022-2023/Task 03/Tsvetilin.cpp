#include <vector>
#include <iostream>
#include <unordered_map>

std::unordered_map<size_t, std::vector<size_t>> g;
std::unordered_map<size_t, bool> visited;

bool hasCycle = false;

void dfs(size_t root)
{
    if (visited[root] || hasCycle)
    {
        hasCycle = true;
        return;
    }

    visited[root] = true;

    for (auto &iter : g[root])
    {
        dfs(iter);
    }

    visited[root] = false;
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        size_t v, e;
        std::cin >> v >> e;

        visited.clear();
        hasCycle = false;
        g.clear();

        size_t x, y, w;
        for (size_t j = 0; j < e; j++)
        {
            std::cin >> x >> y >> w;
            g[x].push_back(y);
        }

        for (auto &iter : g)
        {
            dfs(iter.first);
            if (hasCycle)
            {
                std::cout << "true ";
                break;
            }
        }

        if (!hasCycle)
        {
            std::cout << "false ";
        }
    }

    return 0;
}
