#include <iostream>
#include <unordered_map>

std::vector<std::pair<size_t, size_t>> g[1005];
std::unordered_map<size_t, std::unordered_map<size_t, size_t>> hasConnection;

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    size_t x, y, w;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
        hasConnection[x][y] = w;
        hasConnection[y][x] = w;
    }

    size_t k;
    std::cin >> k;
    std::vector<size_t> path(k);
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> path[i];
    }

    size_t sum = 0;

    for (size_t i = 0; i < k - 1; i++)
    {
        if (hasConnection[path[i]][path[i + 1]])
        {
            sum += hasConnection[path[i]][path[i + 1]];
        }
        else
        {
            std::cout << "-1";
            return 0;
        }
    }

    std::cout << sum;

    return 0;
}
