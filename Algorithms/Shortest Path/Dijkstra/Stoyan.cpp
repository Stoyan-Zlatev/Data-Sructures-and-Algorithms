#include <bits/stdc++.h>

using namespace std;

struct Node {
    size_t destination;
    size_t weight;

    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

unordered_map<size_t, vector<Node>> graph;

void findShortestPath(const size_t &startNode, size_t *distances) {
    distances[startNode] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({startNode, 0});

    while (!pq.empty()) {
        size_t currentNode = pq.top().destination;
        size_t distance = pq.top().weight;
        pq.pop();

        if (distance > distances[currentNode]) {
            continue;
        }

        for (const auto &neighbour: graph[currentNode]) {
            size_t nextNode = neighbour.destination;
            size_t distanceToNextStop = neighbour.weight;
            size_t totalDistance = distances[currentNode] + distanceToNextStop;

            if (distances[nextNode] > totalDistance) {
                distances[nextNode] = totalDistance;
                pq.push({nextNode, totalDistance});
            }
        }
    }
}

int main() {
    size_t T, N, M, from, to, distance, start;
    cin >> T;

    for (int j = 0; j < T; ++j) {
        cin >> N >> M;

        for (size_t i = 0; i < M; ++i) {
            cin >> from >> to >> distance;
            graph[from].push_back({to, distance});
            graph[to].push_back({from, distance});
        }

        size_t distances[N + 1];
        for (size_t i = 0; i <= N; ++i) {
            distances[i] = INT_MAX;
        }

        cin >> start;

        findShortestPath(start, distances);

        for (size_t i = 1; i <= N; ++i) {
            if (i != start) {
                if (distances[i] != INT_MAX) {
                    cout << distances[i] << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        }
        graph.clear();
    }

}
