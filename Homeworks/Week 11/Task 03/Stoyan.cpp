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

const size_t MOD = 1e9 + 7;


size_t findShortestPath(const size_t &start, const size_t& stop, const size_t &N) {
    vector<size_t> distances(N, LLONG_MAX);
    vector<size_t> paths(N, 0);

    distances[start] = 0;
    paths[start] = 1;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        size_t currentStop = pq.top().destination;
        size_t currentDistance = pq.top().weight;
        pq.pop();

        if (currentDistance > distances[currentStop]) {
            continue;
        }

        for (const auto &neighbour: busMap[currentStop]) {
            size_t nextStop = neighbour.destination;
            size_t distanceToNextStop = neighbour.weight;
            size_t nextStopTime = distances[currentStop] + distanceToNextStop;

            if (distances[nextStop] > nextStopTime) {
                distances[nextStop] = nextStopTime;
                pq.push({nextStop, nextStopTime});
            }

            if (distances[nextStop] > distances[currentStop]) {
                paths[nextStop] += paths[currentStop];
                paths[nextStop] %= MOD;
            }
        }
    }

    return paths[stop];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t V, E, start, stop, A, B, dist;
    cin >> V >> E >> start >> stop;

    for (size_t i = 0; i < E; ++i) {
        cin >> A >> B >> dist;
        busMap[A].push_back({B, dist});
        busMap[B].push_back({A, dist});
    }

    cout << findShortestPath(stop, start, V);

    return 0;
}
