#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;

void bfs(size_t start, set <size_t> &forbidden, vector <size_t> &dist) {
    dist[start] = 0;
    queue <size_t> q;
    q.push(start);
    while (!q.empty()) {
        size_t current = q.front();
        visited[current] = true;
        q.pop();
        for (const auto &element: graph[current]) {
            if (!visited[element] && forbidden.find(element) == forbidden.end()) {
                dist[element] = min(dist[element], dist[current] + 1);
                q.push(element);
            }
        }
    }
}

int main() {
    size_t N, M, P, K, from, to, node;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cin >> P;
    queue <size_t> path;
    set <size_t> forbidden;

    for (size_t i = 0; i < P; ++i) {
        cin >> to;
        path.push(to);
        forbidden.insert(to);
    }

    cin >> K;
    for (size_t i = 0; i < K; ++i) {
        cin >> to;
        forbidden.insert(to);
    }

    from = path.front();
    forbidden.erase(from);
    path.pop();
    size_t sum = 0;
    for (size_t i = 1; i < P; ++i) {
        to = path.front();
        forbidden.erase(to);
        path.pop();
        vector <size_t> dist(N + 1, INT_MAX);
        bfs(from, forbidden, dist);
        sum += dist[to];
        from = to;
        visited.clear();
    }

    cout << sum;
    return 0;
}
