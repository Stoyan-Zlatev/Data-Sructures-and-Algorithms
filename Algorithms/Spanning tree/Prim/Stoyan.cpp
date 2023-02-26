#include <bits/stdc++.h>

using namespace std;

struct Node {
    size_t to;
    size_t weight;

    bool operator<(const Node &other) const {
        return this->weight < other.weight;
    }
};
unordered_map<size_t, vector<Node>> graph;


size_t minKey(const size_t *key, const bool *visited, const size_t &N) {
    size_t min = INT_MAX, minIndex;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

size_t prim(const size_t &N) {
    size_t totalWeight = 0;
    long long parent[N +1];
    size_t key[N+1];
    bool visited[N +1];

    for (size_t i = 0; i <= N; ++i) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[1] = 0;
    parent[0] = -1;

    for (int i = 0; i < N; ++i) {
        int u = minKey(key, visited, N);
        visited[u] = true;
        totalWeight += key[u];
        for (const auto& neighbour: graph[u])
        {
            if (!visited[neighbour.to] && neighbour.weight < key[neighbour.to])
            {
                parent[neighbour.to] = u;
                key[neighbour.to] = neighbour.weight;
            }
        }
    }

    return totalWeight;
}


int main() {
    size_t N, M, from, to, weight;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    cout <<  prim(N);
    return 0;
}
