#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t to, weight;
};

size_t searchedLength;
unordered_map <size_t, size_t> results;
unordered_map<size_t, bool> visited;
unordered_map <size_t, vector<Edge>> graph;


void dfs(size_t current, size_t depth, size_t currentSum) {
    if (searchedLength == depth) {
        results[currentSum]++;
        return;
    }

    visited[current] = true;

    for (auto &edge: graph[current]) {
        if (!visited[edge.to]) {
            dfs(edge.to, depth + 1, currentSum + edge.weight);
        }
    }

    visited[current] = false;
}

int main() {
    size_t N, M, from, to, weight;
    cin >> N >> M;

    for (size_t i = 0; i < M; i++) {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    cin >> searchedLength;

    for (size_t i = 0; i <= N; i++) {
        visited.clear();
        dfs(i, 0, 0);
    }

    long long result = -1, max = 0;
    for (const auto &element: results) {
        if (element.second > max || (element.second == max && element.first > result)) {
            max = element.second;
            result = element.first;
        }
    }

    cout << result;
    return 0;
}
