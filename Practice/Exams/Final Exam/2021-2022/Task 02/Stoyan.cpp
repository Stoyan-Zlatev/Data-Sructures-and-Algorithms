#include <bits/stdc++.h>

using namespace std;
struct Edge {
    size_t to, weight;
    bool operator>(const Edge& other) const {
        return this->weight > other.weight;
    }
};
unordered_map<size_t, vector<Edge>> graph;

void findShortestPath(size_t value, vector<size_t>& dist) {
    dist[value] = 0;
    queue<Edge> pq;
    pq.push({value, 0});

    while(!pq.empty()) {
        size_t currentNode = pq.front().to;
        size_t currentDistance = pq.front().weight;
        pq.pop();
        if (currentDistance > dist[currentNode]) {
            continue;
        }

        for (const auto& element: graph[currentNode]) {
            size_t nextNode = element.to;
            size_t nextDistance = element.weight;
            size_t totalDistance = currentDistance + nextDistance;

            if (totalDistance < dist[nextNode]) {
                dist[nextNode] = totalDistance;
                pq.push({nextNode, totalDistance});
            }
        }
    }
}

int main() {
    size_t Q, N, M, from, to, start;
    cin >> Q;

    for (size_t k = 0; k < Q; ++k) {
        cin >> N >> M;
        vector<size_t> dist(N+1, INT_MAX);
        for (size_t i = 0; i < M; ++i) {
            cin >> from >> to;
            graph[from].push_back({to, 6});
            graph[to].push_back({from, 6});
        }

        cin >> start;
        findShortestPath(start, dist);
        for (size_t i = 1; i <= N; ++i) {
            if (i != start) {
                if (dist[i] != INT_MAX)
                    cout << dist[i] << " ";
                else
                    cout << -1 << " ";
            }
        }
        graph.clear();
        cout << '\n';
    }
    return 0;
}
