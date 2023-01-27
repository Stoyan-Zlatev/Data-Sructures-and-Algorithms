#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> townMap;

void bfs(size_t startPoint, size_t *dist, bool *visited) {
    queue <size_t> q;

    for (size_t i = 0; i < startPoint; ++i) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    q.push(startPoint);
    visited[startPoint] = true;
    dist[startPoint] = 0;

    while (!q.empty()) {
        size_t top = q.front();
        q.pop();
        for (const auto &element: townMap[top]) {
            if (!visited[element]) {
                visited[element] = true;
                dist[element] = min(dist[top] + 1, dist[element]);
                q.push(element);
            }
        }
    }
}


int main() {
    size_t N, M, K, start, end;
    cin >> N >> M >> K;

    bool visited[N + 1];
    size_t dist[N + 1];

    for (size_t i = 0; i < M; i++) {
        cin >> start >> end;
        townMap[start].push_back(end);
        townMap[end].push_back(start);
        if (i <= N) {
            visited[i] = false;
            dist[i] = INT_MAX;
        }
    }

    bfs(N, dist, visited);
    bool found = false;
    for (size_t i = 1; i <= N; i++) {
        if (dist[i] == K) {
            found = true;
            cout << i << " ";
        }
    }

    if (!found)
        cout << -1;

    return 0;
}
