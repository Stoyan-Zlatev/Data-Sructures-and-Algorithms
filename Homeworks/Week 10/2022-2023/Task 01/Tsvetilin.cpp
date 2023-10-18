#include <iostream>
#include <unordered_map>

const size_t MAX_SIZE = 1e6;

std::unordered_map<size_t, std::vector<size_t>> g;
size_t components[MAX_SIZE + 1]{};
bool visited[MAX_SIZE + 1]{};

void dfs(size_t root, size_t compIndex)
{
    if (visited[root])
    {
        return;
    }

    visited[root] = true;
    components[root] = compIndex;

    for (size_t child : g[root])
    {
        dfs(child, compIndex);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    size_t x, y;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    size_t compIndex = 1;

    for (size_t i = 1; i <= n; i++)
    {
        dfs(i, compIndex++);
    }

    size_t k;
    std::cin >> k;
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> x >> y;
        std::cout << (components[x] == components[y]) << " ";
    }

    return 0;
}