#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Rectangle
{
    size_t upp = 4002;
    size_t down = 0;
    size_t left = 4002;
    size_t right = 0;
};

struct Node
{
    size_t compIndex = 0;
    bool isBurningTree = false;
};

void dfs(size_t x, size_t y, vector<Node> matrix[], size_t N, size_t compIndex, vector<Rectangle> &areas)
{
    if (x >= N || y >= N)
        return;
    if (matrix[x][y].compIndex)
        return;
    if (!matrix[x][y].isBurningTree)
        return;

    matrix[x][y].compIndex = compIndex;
    if (areas[compIndex].upp > x)
        areas[compIndex].upp = x;
    if (areas[compIndex].down < x)
        areas[compIndex].down = x;
    if (areas[compIndex].left > y)
        areas[compIndex].left = y;
    if (areas[compIndex].right < y)
        areas[compIndex].right = y;

    dfs(x - 1, y, matrix, N, compIndex, areas);
    dfs(x + 1, y, matrix, N, compIndex, areas);
    dfs(x, y - 1, matrix, N, compIndex, areas);
    dfs(x, y + 1, matrix, N, compIndex, areas);
}

int main()
{
    size_t N;
    cin >> N;
    vector<Node> matrix[4000];
    vector<pair<size_t, size_t>> coordinates;
    for (size_t i = 0; i < N; i++)
    {
        matrix[i] = vector<Node>(N);
        for (size_t j = 0; j < N; j++)
        {
            cin >> matrix[i][j].isBurningTree;
            if (matrix[i][j].isBurningTree)
            {
                coordinates.push_back({i, j});
            }
        }
    }

    vector<Rectangle> areas(1);
    size_t compIndex = 1;
    for (auto &coordinate : coordinates)
    {
        if (matrix[coordinate.first][coordinate.second].compIndex != 0)
            continue;
        areas.push_back(Rectangle());
        dfs(coordinate.first, coordinate.second, matrix, N, compIndex, areas);
        compIndex++;
    }
    priority_queue<size_t> finalAreas;
    for (size_t i = 1; i < compIndex; i++)
    {
        finalAreas.push((areas[i].down - areas[i].upp + 1) * (areas[i].right - areas[i].left + 1));
    }
    while (!finalAreas.empty())
    {
        cout << finalAreas.top() << " ";
        finalAreas.pop();
    }

    return 0;
}
