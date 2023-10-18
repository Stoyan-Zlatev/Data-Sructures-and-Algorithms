#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;

set <size_t> nodes;
bool isCyclic = false;

void dfs(size_t value) {
    nodes.insert(value);
    for (const auto &element: graph[value]) {
        if (nodes.find(element) != nodes.end()) {
            isCyclic = true;
            return;
        }
        dfs(element);
    }

    nodes.erase(value);
}


int main() {
    size_t Q, N, M, from, to, weight;
    cin >> Q;

    for (size_t i = 0; i < Q; ++i) {
        cin >> N >> M;
        for (size_t j = 0; j < M; ++j) {
            cin >> from >> to >> weight;
            graph[from].push_back(to);
        }

        for (size_t j = 1; j <= N; ++j) {
            dfs(j);
        }
        cout << (isCyclic ? "true" : "false") << " ";
        graph.clear();
        isCyclic = false;
        nodes.clear();
    }

    return 0;
}
