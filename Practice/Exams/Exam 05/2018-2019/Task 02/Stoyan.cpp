#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;

void bfs(size_t N, size_t startPoint, size_t *distance, bool *visited) {
    queue <size_t> queue;

    for (size_t i = 0; i <= N; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    visited[startPoint] = true;
    distance[startPoint] = 0;
    queue.push(startPoint);

    while (!queue.empty()) {
        size_t top = queue.front();
        queue.pop();
        for (const auto &element: graph[top]) {
            if (!visited[element]) {
                visited[element] = true;
                distance[element] = distance[top] + 1;
                queue.push(element);
            }
        }
    }
}

int main() {
    size_t K, start, end;
    cin >> K;

    for (size_t i = 0; i < K; i++) {
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    size_t distance[K + 1];
    bool visited[K + 1];
    size_t sum = 0;
    bfs(K, 0, distance, visited);
    for (size_t i = 1; i <= K; ++i) {
        if (visited[i]) {
            sum += distance[i];
        }
    }

    cout << sum;
    return 0;
}