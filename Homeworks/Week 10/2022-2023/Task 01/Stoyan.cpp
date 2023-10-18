#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, list<size_t>> graph;
unordered_map<size_t, pair<bool, size_t>> visited;
size_t componentCounter = 0;

void dfs(size_t value) {
    visited[value] = {true, componentCounter};
    for (const size_t &element: graph[value]) {
        if (!visited[element].first) {
            dfs(element);
        }
    }
}

void traverse(size_t N) {
    for (size_t i = 1; i <= N; ++i) {
        if (!visited[i].first) {
            dfs(i);
            componentCounter++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    size_t N, M, K, first, second;
    cin >> N >> M;

    for (size_t i = 0; i < M; i++) {
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    cin >> K;
    traverse(N);
    for (size_t i = 0; i < K; i++) {
        cin >> first >> second;
        cout << (visited[first].second == visited[second].second) << " ";
    }

    return 0;
}
