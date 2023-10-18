#include <bits/stdc++.h>

std::unordered_map<size_t, std::set<size_t>> graph;

void bfs(size_t startPoint, size_t N, size_t *dist) {
    std::queue<size_t> q;
    bool visited[N + 1];

    for (size_t i = 0; i <= N; ++i) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    visited[startPoint] = true;
    dist[startPoint] = 0;
    q.push(startPoint);
    size_t visitedNodes = 1;

    while (!q.empty()) {
        if (visitedNodes == N) {
            break;
        }

        size_t top = q.front();
        q.pop();
        for (size_t i = 1; i <= N; ++i) {
            if (!visited[i] && graph[top].find(i) == graph[top].end()) {
                visited[i] = true;
                dist[i] = std::min(dist[i], dist[top] + 1);
                q.push(i);
                visitedNodes++;
            }
        }
    }
}

int main() {
    size_t Q, N, M, start, end, startPoint;
    std::cin >> Q;

    for (size_t i = 0; i < Q; ++i) {
        std::cin >> N >> M;
        for (size_t j = 0; j < M; ++j) {
            std::cin >> start >> end;
            graph[start].insert(end);
            graph[end].insert(start);
        }

        std::cin >> startPoint;

        size_t dist[N + 1];
        bfs(startPoint, N, dist);
        for (size_t index = 1; index <= N; ++index) {
            if (index != startPoint) {
                std::cout << (dist[index] != INT_MAX ? dist[index] : -1) << " ";
            }
        }

        std::cout << '\n';
        graph.clear();
    }

    return 0;
}
