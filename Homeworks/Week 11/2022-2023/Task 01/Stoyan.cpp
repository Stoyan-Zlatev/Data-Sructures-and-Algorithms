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

void findShortestPath(const size_t &startNode, size_t *nodeDistances, const size_t *intervals) {
    nodeDistances[startNode] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({startNode, 0});

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
            size_t currentTravelTime = currentDistance;
            size_t waitToArrive = currentTravelTime % intervals[currentStop];
            waitToArrive = waitToArrive ? intervals[currentStop] - waitToArrive : waitToArrive;
            currentTravelTime += waitToArrive + distanceToNextStop;
            if (nodeDistances[nextStop] > currentTravelTime) {
                nodeDistances[nextStop] = currentTravelTime;
                pq.push({nextStop, currentTravelTime});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t V, E, start, stop, A, B, dist;
    cin >> V >> E >> start >> stop;
    size_t intervals[V];
    size_t nodeDistances[V];

    for (size_t i = 0; i < V; ++i) {
        nodeDistances[i] = INT_MAX;
        cin >> intervals[i];
    }

    for (size_t i = 0; i < E; ++i) {
        cin >> A >> B >> dist;
        busMap[A].push_back({B, dist});
    }

    findShortestPath(start, nodeDistances, intervals);
    if (nodeDistances[stop] != INT_MAX) {
        cout << nodeDistances[stop];
    } else {
        cout << -1;
    }

    return 0;
}
