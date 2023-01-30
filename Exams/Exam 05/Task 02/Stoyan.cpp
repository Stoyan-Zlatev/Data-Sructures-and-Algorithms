#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
size_t result = 0;

size_t dfs(size_t value) {
    visited[value] = true;
    size_t totalCount = 1;
    for (const auto &element: graph[value]) {
        if (!visited[element]) {
            size_t count = dfs(element);
            if (!(count & 1) && count != 0) {
                result++;
            } else {
                totalCount += count;
            }
        }
    }

    return totalCount;
}


int main() {
    size_t N, M, from, to;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(from);
    cout << result;
}