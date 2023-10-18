#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
unordered_map <size_t, size_t> sums;

void dfs(size_t current) {
    visited[current] = true;
    for (const auto &element: graph[current]) {
        if (!visited[element]) {
            dfs(element);
        }
        sums[current] += sums[element] + element;
    }
}


int main() {
    size_t M, T, from, to;
    cin >> M >> T;
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
    }

    for (size_t i = 0; i < T; ++i) {
        cin >> from;
        if (!visited[from]) {
            dfs(from);
        }
        cout << sums[from] << '\n';
    }
    return 0;
}
