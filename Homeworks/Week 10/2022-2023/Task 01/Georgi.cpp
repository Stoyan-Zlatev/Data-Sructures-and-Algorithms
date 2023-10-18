#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    size_t componentIndex = 0;
    unordered_set<size_t> nodes;
};

bool dfs(size_t node, unordered_map<size_t, Node>& graph, unordered_set<size_t>& visited, size_t& componentIndex) {
    visited.insert(node);
    graph[node].componentIndex = componentIndex;

    for (auto iter = graph[node].nodes.begin(); iter != graph[node].nodes.end(); ++iter) {
        if (!visited.count(*iter)) {
            dfs(*iter, graph, visited, componentIndex);
        }
    }

    return false;
}

void createComponents(unordered_map<size_t, Node>& graph) {
    unordered_set<size_t> visited;
    size_t componentIndex = 0;
    for (auto& kvp : graph) {
        if (!visited.count(kvp.first)) {
            dfs(kvp.first, graph, visited, componentIndex);
            componentIndex++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;
    unordered_map<size_t, Node> graph;
    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;
        graph[first - 1].nodes.insert(second - 1);
        graph[second - 1].nodes.insert(first - 1);
    }

    createComponents(graph);

    size_t queriesCount;
    cin >> queriesCount;
    for (size_t i = 0; i < queriesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;

        std::cout << (graph[first - 1].componentIndex == graph[second - 1].componentIndex) << ' ';
    }

    return 0;
}