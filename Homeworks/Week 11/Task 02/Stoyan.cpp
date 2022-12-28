#include <bits/stdc++.h>

using namespace std;

struct Node {
    size_t destination;
    size_t weight;

    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

unordered_map<size_t, vector<Node>> busMap;

void findShortestPath(const size_t &V, const size_t &N, vector<size_t> &nodeDistances) {
    nodeDistances[V] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({V, 0});

    while (!pq.empty()) {
        size_t currentStop = pq.top().destination;
        size_t currentDistance = pq.top().weight;
        pq.pop();

        if (currentDistance > nodeDistances[currentStop]) {
            continue;
        }

        for (const auto &neighbour: busMap[currentStop]) {

            size_t nextStop = neighbour.destination;
            size_t distanceToNextStop = neighbour.weight;

            if (nodeDistances[nextStop] > currentDistance + distanceToNextStop) {
                nodeDistances[nextStop] = currentDistance + distanceToNextStop;
                pq.push({nextStop, distanceToNextStop + currentDistance});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t V, E, Q, start, stop, dist;
    cin >> V >> E >> Q;

    for (size_t i = 0; i < E; ++i) {
        cin >> start >> stop >> dist;
        busMap[start].push_back({stop, dist});
    }

    vector<vector<size_t>> distances(V);
    for (int i = 0; i < V; ++i) {
        distances[i] = vector<size_t>(V, INT_MAX);
        findShortestPath(i, V, distances[i]);
    }
    
    for (size_t i = 0; i < Q; ++i) {
        cin >> start >> stop;
        if (distances[start][stop] != INT_MAX) {
            cout << distances[start][stop] << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }
    return 0;
}
