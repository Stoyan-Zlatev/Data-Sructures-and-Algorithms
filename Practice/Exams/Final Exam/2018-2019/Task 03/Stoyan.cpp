#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
size_t components = 0;

void dfs(size_t value) {
    visited[value] = true;
    for (const auto &element: graph[value]) {
        if (!visited[element]) {
            dfs(element);
        }
    }
}

void traverse(size_t N) {
    for (size_t i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
}

int main() {
    size_t T, N, M, from, to;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        cin >> N >> M;
        for (size_t j = 0; j < M; ++j) {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);

        }
        traverse(N);
        cout << components << " ";
        graph.clear();
        visited.clear();
        components = 0;
    }

    return 0;
}
