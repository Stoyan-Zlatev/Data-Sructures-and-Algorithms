#include <bits/stdc++.h>

using namespace std;

vector<pair<size_t, pair<size_t, size_t>>> graph;
vector<pair<size_t, pair<size_t, size_t>>> tree;

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

void kruskal(size_t *parent) {
    sort(graph.begin(), graph.end());
    for (size_t i = 0; i < graph.size(); ++i) {
        size_t u = find(graph[i].second.first, parent);
        size_t v = find(graph[i].second.second, parent);

        if (u != v) {
            tree.push_back(graph[i]);
            connect(u, v, parent);
        }
    }
}


int main() {
    size_t N, M;
    cin >> N >> M;
    size_t parent[N];
    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }
    //init graph
    kruskal(parent);
}
