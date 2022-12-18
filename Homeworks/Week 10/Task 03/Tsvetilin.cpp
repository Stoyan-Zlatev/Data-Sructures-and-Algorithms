#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

typedef std::unordered_map<size_t, std::set<size_t>> graph;
typedef std::unordered_map<size_t, size_t> dic;
typedef std::vector<size_t> vec;

graph g;
dic paths;
dic visited;
std::set<size_t> allVertex;

size_t n;

void bfs(size_t root)
{
    std::queue<long long> q;
    q.push(root);
    q.push(-1);
    visited[root] = 1;

    size_t level = 0;

    while (true)
    {
        long long current = q.front();
        q.pop();

        if (q.size() == 0)
            break;

        if (current == -1)
        {
            q.push(-1);
            level++;
            continue;
        }

        paths[current] = level;

        std::vector<size_t> v(allVertex.size());
        auto resEnd = std::set_difference(
            allVertex.begin(), allVertex.end(), g[current].begin(), g[current].end(), v.begin());

        for (auto iter = v.begin(); iter != resEnd; iter++)
        {
            if (!visited[*iter])
            {
                allVertex.erase(*iter);
                q.push(*iter);
                visited[*iter] = 1;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t q;
    std::cin >> q;

    for (size_t i = 0; i < q; i++)
    {

        size_t m;
        std::cin >> n >> m;

        allVertex.clear();
        for (size_t j = 0; j < n; j++)
        {
            allVertex.insert(j + 1);
        }

        size_t x, y;
        for (size_t j = 0; j < m; j++)
        {
            std::cin >> x >> y;
            g[x].insert(y);
            g[y].insert(x);
        }

        size_t k;
        std::cin >> k;
        bfs(k);

        for (size_t j = 1; j <= n; j++)
        {
            if (j == k)
                continue;

            if (paths[j] == 0)
                std::cout << -1 << " ";
            else
                std::cout << paths[j] << " ";
        }

        std::cout << "\n";

        g.clear();
        paths.clear();
        visited.clear();
    }

    return 0;
}