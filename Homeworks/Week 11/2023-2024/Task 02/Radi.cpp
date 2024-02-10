#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

size_t N, M;

unordered_map<size_t, size_t> graph[1007 * 1007];
size_t dist[1007][1007];
priority_queue<pair<pair<size_t, size_t>, size_t>, vector<pair<pair<size_t, size_t>, size_t>>, greater<pair<pair<size_t, size_t>, size_t>>> pq;

bool canMove(size_t x, size_t y)
{
    return x < N - 1 && x > 0 && y < M - 1 && y > 0;
}

void shortestPathDijkstra()
{
    while (!pq.empty())
    {

        pair<size_t, size_t> current = pq.top().first;
        size_t x = current.second;
        size_t y = pq.top().second;
        pq.pop();
        size_t cost = current.first;

        size_t checkX = 3;
        size_t checkY = 12;
        if (canMove(x - 1, y))
        {
            if (dist[x - 1][y] > cost + graph[x - 1][y])
            {
                dist[x - 1][y] = cost + graph[x - 1][y];
                pq.push({{cost + graph[x - 1][y], x - 1}, y});
            }
        }
        if (canMove(x + 1, y))
        {
            if (dist[x + 1][y] > cost + graph[x + 1][y])
            {
                dist[x + 1][y] = cost + graph[x + 1][y];
                pq.push({{cost + graph[x + 1][y], x + 1}, y});
            }
        }
        if (canMove(x, y - 1))
        {
            if (dist[x][y - 1] > cost + graph[x][y - 1])
            {
                dist[x][y - 1] = cost + graph[x][y - 1];
                pq.push({{cost + graph[x][y - 1], x}, y - 1});
            }
        }
        if (canMove(x, y + 1))
        {
            if (dist[x][y + 1] > cost + graph[x][y + 1])
            {
                dist[x][y + 1] = cost + graph[x][y + 1];
                pq.push({{cost + graph[x][y + 1], x}, y + 1});
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    char temp;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> temp;
            graph[i][j] = (temp == '#' ? 1 : 0);
            dist[i][j] = INT_MAX;
        }
    }

    for (size_t i = 0; i < M; i++)
    {
        dist[0][i] = graph[0][i];
        dist[N - 1][i] = graph[N - 1][i];
        pq.push({{graph[0][i], 0}, i});
        pq.push({{graph[N - 1][i], N - 1}, i});
    }

    for (size_t i = 1; i < N - 1; i++)
    {
        dist[i][0] = graph[i][0];
        dist[i][M - 1] = graph[i][M - 1];
        pq.push({{graph[i][0], i}, 0});
        pq.push({{graph[i][M - 1], i}, M - 1});
    }

    shortestPathDijkstra();
    size_t maxDist = 0;
    for (size_t i = 1; i < N - 1; i++)
    {
        for (size_t j = 1; j < M - 1; j++)
        {
            if (graph[i][j] == 0 && dist[i][j] > maxDist)
            {
                maxDist = dist[i][j];
            }
        }
    }
    size_t count = 0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            count += (!graph[i][j] && dist[i][j] == maxDist);
        }
    }

    cout << count;

    return 0;
}
