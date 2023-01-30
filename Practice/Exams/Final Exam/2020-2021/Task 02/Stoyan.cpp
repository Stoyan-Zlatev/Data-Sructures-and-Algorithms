#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map <size_t, size_t> visited;
size_t componentCounter = 1;

void dfs(const size_t &value) {
    visited[value] = componentCounter;
    for (const auto &element: graph[value]) {
        if (!visited[element]) {
            dfs(element);
        }
    }
}

void traverse(const size_t &N) {
    for (size_t i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            componentCounter++;
        }
    }
}

int main() {
    size_t N, M, Q, from, to;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    traverse(N);

    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> from >> to;
        cout << (visited[from] == visited[to]) << " ";
    }
    return 0;
}