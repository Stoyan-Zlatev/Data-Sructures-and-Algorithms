#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t to, weight;

    bool operator>(const Edge& other) const {
        return this->weight > other.weight;
    }
};

unordered_map<size_t, vector<Edge>> townMap;

void findShortestPath(const size_t& value, vector<size_t>& distances) {
    distances[value] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({value, 0});

    while (!pq.empty()) {
        size_t currentNode = pq.top().to;
        size_t currentDistance = pq.top().weight;
        pq.pop();

        if (currentDistance > distances[currentNode]) {
            continue;
        }

        for (const auto& element: townMap[currentNode]) {
            size_t nextNode = element.to;
            size_t nextDistance = element.weight;
            size_t totalDistance = nextDistance + currentDistance;

            if (totalDistance < distances[nextNode]) {
                distances[nextNode] = totalDistance;
                pq.push({nextNode, totalDistance});
            }
        }
    }
}

int main() {
    size_t N, M, from, to, weight, start;
    cin >> N >> M;
    vector<size_t> distances(N + 1, INT_MAX);
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        townMap[from].push_back({to, weight});
        townMap[to].push_back({from, weight});
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
}