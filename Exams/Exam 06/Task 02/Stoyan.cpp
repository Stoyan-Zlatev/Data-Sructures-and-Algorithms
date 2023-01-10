#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, unordered_map<size_t, size_t>> graph;

int main() {
    size_t N, M, K, from, to, weight, node;
    cin >> N >> M;
    
    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        graph[from][to] = weight;
        graph[to][from] = weight;
    }
    
    cin >> K;
    cin >> from;
    size_t sum = 0;
    for (size_t i = 0; i < K - 1; ++i) {
        cin >> node;
 if (graph.count(from) && graph[from].count(node)) {
            sum += graph[from][node];
        } else {
            cout << -1;
            return 0;
        }
        
        from = node;
    }
    
    cout << sum;
    return 0;
}
