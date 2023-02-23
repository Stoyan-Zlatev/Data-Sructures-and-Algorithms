#include <iostream>
#include <unordered_map>

std::unordered_map<size_t, std::vector<size_t>> g;
std::unordered_map<size_t, bool> visited;
int current = 0;

void dfs(size_t root)
{

    if (visited[root])
    {
        return;
    }

    visited[root] = true;

    for (auto &iter : g[root])
    {
        dfs(iter);
    }
}

int main()
{
    size_t t;
    std::cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        size_t x, y;
        std::cin >> x >> y;

        size_t a, b;
        g.clear();
        visited.clear();
        current = 0;
        for (size_t j = 0; j < y; j++)
        {
            std::cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for (size_t iter = 0; iter < x; iter++)
        {
            if (visited[iter])
            {
                continue;
            }

            dfs(iter);
            current++;
        }

        std::cout << current << " ";
    }

    return 0;
}
