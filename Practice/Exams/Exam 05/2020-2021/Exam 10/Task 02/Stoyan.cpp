#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t to, weight;
};

unordered_map <size_t, vector<Edge>> graph;
unordered_map <size_t, size_t> results;

void dfs(const size_t &value, unordered_map<size_t, bool> &visited, const size_t &K, size_t depth = 0, size_t sum = 0) {
    if (depth == K) {
        results[sum]++;
        return;
    }
    visited[value] = true;
    for (const auto &element: graph[value]) {
        if (!visited[element.to]) {
            dfs(element.to, visited, K, depth + 1, sum + element.weight);
        }
    }

    visited[value] = false;
}

void traverse(const size_t &N, const size_t &K) {
    for (size_t i = 1; i <= N; ++i) {
        unordered_map<size_t, bool> visited;
        dfs(i, visited, K);
    }
}

int main() {
    size_t N, M, K, from, to, weight;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    cin >> K;
    traverse(N, K);
    size_t maxCount = 0, maxSum = 0;
    if (results.empty()) {
        cout << -1;
        return 0;
    }

    for (const auto &element: results) {
        if (element.second > maxCount || (element.second == maxCount && maxSum < element.first)) {
            maxCount = element.second;
            maxSum = element.first;
        }
    }

    cout << maxSum;
    return 0;
}