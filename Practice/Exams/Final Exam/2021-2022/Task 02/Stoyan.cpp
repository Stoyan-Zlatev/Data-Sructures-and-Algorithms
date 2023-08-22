#include <bits/stdc++.h>

using namespace std;

struct Edge {
    size_t to, weight;
    
    bool operator>(const Edge& other) const {
        return this->weight >= other.weight;
    }
};

unordered_map<size_t, vector<Edge>> graph;

void findShortestPath(size_t start, vector<size_t>& dist) {
    dist[start] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        size_t currentNode = pq.top().to;
        size_t currentDistance = pq.top().weight;
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
    
    for (size_t j = 0; j < Q; ++j) {
        cin >> N >> M;
        vector<size_t> dist(N + 1, INT_MAX);
        for (size_t i = 0; i < M; ++i) {
            cin >> from >> to;
            graph[from].push_back({to, 6});
            graph[to].push_back({from, 6});
        }
        cin >> start;
        findShortestPath(start, dist);
        for (size_t i = 1; i <= N; ++i) {
            if (i != start) {
                if (dist[i] == INT_MAX) {
                    cout << -1 << " ";
                } else {
                    cout << dist[i] << " ";
                }
            }
        }
        cout << "\n";
        graph.clear();
    }
    
    return 0;
}
