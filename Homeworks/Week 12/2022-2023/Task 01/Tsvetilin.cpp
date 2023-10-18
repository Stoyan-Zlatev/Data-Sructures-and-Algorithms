#include <vector>
#include <iostream>
#include <algorithm>

const size_t MAX_SIZE = 1e3 + 5;
std::vector<size_t> g[MAX_SIZE];
int components[MAX_SIZE]{};

void dfs(size_t root, size_t currentComp)
{
    if (components[root] != 0)
        return;

    components[root] = currentComp;

    for (auto x : g[root])
    {
        dfs(x, currentComp);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t m, n;
    std::cin >> n >> m;

    int x, y, z;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (size_t i = 1; i <= n; i++)
    {
        dfs(i, i);
    }

    size_t q;
    std::cin >> q;

    for (size_t i = 0; i < q; i++)
    {
        std::cin >> x >> y >> z;
        if (x == 2)
        {
            if (components[y] == components[z])
                continue;

            size_t targetChange = components[z];
            for (size_t j = 1; j <= n; j++)
            {
                if (components[j] == targetChange)
                    components[j] = components[y];
            }
        }
        else
            std::cout << (components[y] == components[z]);
    }

    return 0;
}