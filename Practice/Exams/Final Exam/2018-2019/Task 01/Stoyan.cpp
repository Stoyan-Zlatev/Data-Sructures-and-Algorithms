#include <bits/stdc++.h>
using namespace std;

unordered_map<size_t, unordered_map<size_t, size_t>> graph;

int main() {
    size_t N, M, Q, from, to, weight;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph[from][to] = weight;
        graph[to][from] = weight;
    }

    cin >> Q;

    cin >> from;
    size_t sum = 0;
    for (size_t i = 1; i < Q; ++i) {
        cin >> to;
        if (graph.find(from) != graph.end() && graph[from].find(to) != graph[from].end()) {
            sum += graph[from][to];
        } else {
            cout << -1;
            return 0;
        }
        from = to;
    }

    cout << sum;
    return 0;
}
