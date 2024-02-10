#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

vector<size_t> graph[size_t(1e6 + 2)];
unordered_set<size_t> friends;

size_t bfs(size_t from)
{
    queue<size_t> q;
    q.push(from);
    bool visited[size_t(1e6 + 2)];
    visited[from] = 1;
    size_t level = 0;

    while (!q.empty())
    {
        size_t sizeQ = q.size();
        level++;
        for (size_t i = 0; i < sizeQ; i++)
        {
            if (friends.count(q.front()) && q.front() != from)
            {
                return level;
            }
            for (auto &neighbour : graph[q.front()])
            {
                if (visited[neighbour])
                {
                    continue;
                }
                q.push(neighbour);
            }
            visited[q.front()] = true;
            q.pop();
        }
    }
    return 0;
}

int main()
{
    size_t N, M;
    cin >> N >> M;
    size_t x, y;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<size_t> friendGroups;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        friendGroups.push_back(x);
    }
    cin >> y;

    for (size_t i = 0; i < N; i++)
    {
        if (friendGroups[i] == y)
        {
            friends.insert(i + 1);
        }
    }

    size_t minDist = -1;
    for (auto &fr : friends)
    {
        size_t dist = bfs(fr);
        if (dist != 0)

        {
            minDist = min(minDist, dist);
        }
    }

    if (minDist != -1)
    {
        cout << minDist - 1;
        return 0;
    }
    cout << -1;
    return 0;
}
