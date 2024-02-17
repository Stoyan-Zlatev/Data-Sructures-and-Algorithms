#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<size_t> graph[10000002];
bool visited[10000002];
size_t components[10000002];

void dfs(size_t node, size_t compIndex)
{
    visited[node] = true;
    components[node] = compIndex;
    for (auto &current : graph[node])
    {
        if (!visited[current])
            dfs(current, compIndex);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N, M, Q, x, y;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cin >> Q;
    size_t compIndex = 1;
    for (size_t i = 0; i < N; i++)
    {
        if (!visited[i])
            dfs(i, compIndex);
        compIndex++;
    }
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x >> y;
        cout << (components[x] == components[y]) << " ";
    }

    return 0;
}
