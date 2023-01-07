#include <bits/stdc++.h>

using namespace std;

struct Node {
    size_t to;
    size_t weight;

    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

unordered_map<size_t, vector<Node>> graph;

void dijkstra(const size_t &startNode, size_t *nodeDistances) {
    nodeDistances[startNode] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({startNode, 0});

    while (!pq.empty()) {
        size_t currentNode = pq.top().to;
        size_t currentWeight = pq.top().weight;
        pq.pop();

        if (currentWeight > nodeDistances[currentNode]) {
            continue;
        }

        for (const auto &neighbour: graph[currentNode]) {
            size_t nextNode = neighbour.to;
            size_t nextWeight = neighbour.weight;
            size_t distanceToNextNode = currentWeight + nextWeight;

            if (nodeDistances[nextNode] > distanceToNextNode) {
                nodeDistances[nextNode] = distanceToNextNode;
                pq.push({nextNode, distanceToNextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t V, E, start, stop, A, B, dist;
    cin >> V >> E >> start >> stop;
    size_t nodeDistances[V];

    for (size_t i = 0; i < E; ++i) {
        cin >> A >> B >> dist;
        graph[A].push_back({B, dist});
    }

    dijkstra(start, nodeDistances);
    if (nodeDistances[stop] != INT_MAX) {
        cout << nodeDistances[stop];
    } else {
        cout << -1;
    }

    return 0;
}
