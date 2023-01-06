#include <bits/stdc++.h>

using namespace std;

struct Key {
    size_t effort, line;
    long long price;

    bool operator<(const Key &other) const {
        return this->effort < other.effort || (this->effort == other.effort && this->price > other.price);
    }
};

const size_t MAX_SIZE = 2 * 1e5 + 5;
vector<pair<Key, pair<size_t, size_t>>> graph;
size_t parent[MAX_SIZE];

size_t findVertex(const size_t v) {
    if (v == parent[v]) {
        return v;
    }
    parent[v] = findVertex(parent[v]);
    return parent[v];
}

void unionVertexes(const size_t &from, const size_t &to) {
    parent[from] = parent[to];
}

void kruskal() {
    size_t u, v;
    sort(graph.begin(), graph.end());
    for (size_t i = 0; i < graph.size(); i++) {
        u = findVertex(graph[i].second.first);
        v = findVertex(graph[i].second.second);
        if (u != v) {
            cout << graph[i].first.line << '\n';
            unionVertexes(u, v);
        }
    }
}

int main() {
    size_t N, M, from, to, effort;
    long long price;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> effort >> price;
        graph.push_back({{effort, i + 1, price},
                         {from,   to}});
    }

    for (size_t i = 0; i < N; ++i) {
        parent[i] = i;
    }

    kruskal();

    return 0;
}
