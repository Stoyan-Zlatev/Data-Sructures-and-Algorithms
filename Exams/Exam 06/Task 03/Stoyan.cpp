#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;

bool hasCycle = false;

void dfs(const size_t& value, set<size_t>& values) {
    visited[value] = true;
    values.insert(value);

    for (const auto &element: graph[value]) {
        if (values.find(element) != values.end()) {
            hasCycle = true;
            return;
        }

        if (!visited[element]) {
            dfs(element, values);
        }
    }

    values.erase(value);
}

void initGraph(const size_t& N) {
    visited.clear();
    graph.clear();
    for (size_t j = 0; j < N; ++j) {
        graph[j];
    }
}

void traverse() {
    set<size_t> values;
    for (const auto &element: graph) {
        if (!visited[element.first]) {
            dfs(element.first, values);
            if (hasCycle) {
                break;
            }
        }
    }
}

int main() {
    size_t Q, N, E, start, end, weight;
    cin >> Q;

    for (size_t i = 0; i < Q; ++i) {
        cin >> N >> E;
        hasCycle = false;
        initGraph(N);
        
        for (size_t j = 0; j < E; j++) {
            cin >> start >> end >> weight;
            graph[start].push_back(end);
        }
        
        traverse();
        cout << (hasCycle? "true" : "false") << " ";
    }
    return 0;
}
