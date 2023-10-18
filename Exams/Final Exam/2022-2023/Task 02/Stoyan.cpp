#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
size_t counter = 0;


void dfs(size_t value) {
    visited[value] = true;
    counter++;
    for (const auto &element: graph[value]) {
        if (!visited[element]) {
            dfs(element);
        }
    }
}

size_t result = 0;

void traverse(size_t N, size_t K) {
    for (size_t i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
            if (counter % K == 0) {
                result++;
            }
            counter = 0;
        }
    }
}

int main() {
    size_t N, M, K, from, to;
    cin >> N >> M >> K;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    traverse(N, K);
    cout << result;
    return 0;
}
