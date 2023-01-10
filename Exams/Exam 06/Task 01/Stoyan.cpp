#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
size_t componentCounter = 0;

void dfs(size_t value) {
    visited[value] = true;
    for (const size_t &element: graph[value]) {
        if (!visited[element]) {
            dfs(element);
        }
    }
}

void traverse(size_t N) {
    for (size_t i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
            componentCounter++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    size_t N, M, T, first, second;
    cin >> T;
    
    for (size_t j=0; j<T; ++j) {
        cin >> N >> M;

        for (size_t i = 0; i < M; i++) {
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }

        traverse(N);
        cout << componentCounter << " ";
        componentCounter = 0;
        graph.clear();
        visited.clear();
    }

    return 0;
}
