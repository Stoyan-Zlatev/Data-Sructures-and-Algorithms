#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> graph;
queue <size_t> path;
set <size_t> pathRoute;

int bfs(size_t start, size_t target) {
    int ans = 0;
    queue <size_t> q;
    q.push(start);
    while (!q.empty()) {
        ans++;
        size_t levelSize = q.size();
        for (size_t i = 0; i < levelSize; ++i) {
            size_t current = q.front();
            q.pop();
            for (const auto &element: graph[current]) {
                if (element == target) {
                    return ans;
                }
                if (pathRoute.find(element) == pathRoute.end()) {
                    q.push(element);
                }
            }
        }
    }

    return -1;
}

int main() {
    size_t N, M, Q, from, to, query;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
    }

    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> from;
        path.push(from);
        pathRoute.insert(from);
    }

    from = path.front();
    path.pop();
    pathRoute.erase(from);
    size_t sum = 0;
    while (!path.empty()) {
        to = path.front();
        path.pop();
        pathRoute.erase(to);
        int result = bfs(from, to);
        if (result == -1) {
            cout << -1;
            return 0;
        } else {
            sum += result;
        }
        from = to;
    }

    cout << sum;
    return 0;
}
