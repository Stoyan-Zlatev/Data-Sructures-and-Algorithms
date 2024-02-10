#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const size_t MAX_CITIES = 1e6 + 2;

vector<size_t> graph[MAX_CITIES * 2 + 20];

bool visited[MAX_CITIES * 2 + 20];

size_t bfs(size_t x, size_t y)
{
    queue<size_t> q;
    q.push(x);

    size_t level = 0;

    while (!q.empty())
    {
        size_t s = q.size();
        level++;
        for (size_t i = 0; i < s; i++)
        {
            visited[q.front()] = true;

            for (auto &n : graph[q.front()])
            {
                if (visited[n])
                    continue;
                if (n == y)
                    return level;
                q.push(n);
            }

            q.pop();
        }
    }

    return level;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N, M;
    cin >> N >> M;

    size_t x, y, d;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> d;
        if (d == 2)
        {
            graph[x].push_back(x + MAX_CITIES);
            graph[x + MAX_CITIES].push_back(y);

            graph[y].push_back(y + MAX_CITIES);
            graph[y + MAX_CITIES].push_back(x);
        }
        else
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    size_t startIndex, endIndex;
    cin >> startIndex >> endIndex;

    cout << bfs(startIndex, endIndex);

    return 0;
}
