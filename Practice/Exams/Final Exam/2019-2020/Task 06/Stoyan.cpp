#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t from, to, weight;

    bool operator>(const Edge &other) const {
        return this->weight > other.weight;
    }
};

vector <Edge> graph;

size_t find(size_t u, vector <size_t> &parent) {
    if (u == parent[u]) {
        return u;
    }

    parent[u] = find(parent[u], parent);
    return parent[u];
}

void connect(size_t u, size_t v, vector <size_t> &parent) {
    parent[u] = parent[v];
}

size_t kruskal(vector <size_t> &parent) {
    size_t sum = 0;
    sort(graph.begin(), graph.end(), greater<Edge>());
    for (size_t i = 1; i <= graph.size(); ++i) {
        size_t u = find(graph[i].from, parent);
        size_t v = find(graph[i].to, parent);

        if (u != v) {
            connect(u, v, parent);
            sum += graph[i].weight;
        }
    }

    return sum;
}

int main() {
    size_t N, M, from, to, weight;
    cin >> N >> M;

    vector <size_t> parent(N + 1);
    for (size_t i = 0; i <= N; ++i) {
        parent[i] = i;
    }
    size_t totalSum = 0;
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph.push_back({from, to, weight});
        graph.push_back({to, from, weight});
        totalSum += weight;
    }

    cout << totalSum - kruskal(parent);
    return 0;
}
