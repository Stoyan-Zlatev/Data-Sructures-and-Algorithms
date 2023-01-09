#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t from, to, weight;

    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
    }
};

vector<Edge> graph;
vector<Edge> tree;

size_t find(size_t v, size_t *parent) {
    if (v == parent[v]) {
        return v;
    }

    parent[v] = find(parent[v], parent);
    return parent[v];
}

void connect(size_t from, size_t to, size_t *parent) {
    parent[from] = parent[to];
}

size_t kruskal(size_t *parent) {
    sort(graph.begin(), graph.end());
    size_t totalWeight = 0;
    for (size_t i = 0; i < graph.size(); ++i) {
        size_t u = find(graph[i].from, parent);
        size_t v = find(graph[i].to, parent);

        if (u != v) {
            totalWeight += graph[i].weight;
            tree.push_back(graph[i]);
            connect(u, v, parent);
        }
    }

    return totalWeight;
}


int main() {
    size_t N, M, from, to, weight;
    cin >> N >> M;
    size_t parent[N];
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph.push_back({from, to, weight});
    }

    for (size_t i = 0; i <= N; ++i) {
        parent[i] = i;
    }

    cout << kruskal(parent);
}
