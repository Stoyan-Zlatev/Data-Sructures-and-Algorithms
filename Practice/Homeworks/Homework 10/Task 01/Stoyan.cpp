#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;

bool hasCycle = false;

void dfs(size_t value, set<size_t> &values) {
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

int main() {
    size_t Q, E, start, end;
    cin >> Q;

    for (size_t i = 0; i < Q; i++) {
        cin >> E;
        hasCycle = false;
        for (size_t j = 0; j < E; j++) {
            cin >> start >> end;
            graph[start].push_back(end);
        }

        set<size_t> values;
        for (const auto &element: graph) {
            if (!visited[element.first]) {
                dfs(element.first, values);
                if (hasCycle) {
                    break;
                }
            }
        }

        cout << hasCycle << " ";
        graph.clear();
        visited.clear();
    }
    return 0;
}
