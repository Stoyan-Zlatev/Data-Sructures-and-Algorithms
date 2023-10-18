#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

const size_t MAX_SIZE = (size_t)1e3 + 5;
std::vector<size_t> g[MAX_SIZE];
std::vector<size_t> seq;
std::unordered_set<size_t> forbidden;
size_t n, m, p;

size_t bfs(size_t root, size_t target)
{
    bool visited[MAX_SIZE]{};
    visited[root] = true;
    std::queue<size_t> q;
    q.push(root);
    size_t level = 0;

    while (!q.empty())
    {
        size_t curSize = q.size();

        for (size_t i = 0; i < curSize; i++)
        {
            size_t current = q.front();
            q.pop();

            if (current == target)
                return level;

            for (auto &iter : g[current])
            {
                if (!visited[iter] && forbidden.find(current) == forbidden.end())
                {
                    q.push(iter);
                    visited[iter] = true;
                }
            }
        }

        level++;
    }

    return level;
}

size_t solve()
{
    size_t sum = 0;
    forbidden.erase(seq[0]);
    for (size_t i = 0; i < p - 1; i++)
    {
        forbidden.erase(seq[i + 1]);
        sum += bfs(seq[i], seq[i + 1]);
    }

    return sum;
}

int main()
{

    std::cin >> n >> m;
    size_t x, y;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    std::cin >> p;
    for (size_t i = 0; i < p; i++)
    {
        std::cin >> x;
        seq.push_back(x);
        forbidden.insert(x);
    }

    std::cin >> y;
    for (size_t i = 0; i < y; i++)
    {
        std::cin >> x;
        forbidden.insert(x);
    }

    std::cout << solve();

    return 0;
}
