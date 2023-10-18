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
    long long componentIndex = -1;
    unordered_set<size_t> nodes; // can't access directly these nodes
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

// returns components count
size_t createComponents(unordered_map<size_t, Node>& graph) {
    unordered_set<size_t> visited;
    size_t componentIndex = 0;
    for (auto& kvp : graph) {
        if (!visited.count(kvp.first)) {
            dfs(kvp.first, graph, visited, componentIndex);
            componentIndex++;
        }
    }

    return componentIndex;
}

long long calculatePathLengths(
    unordered_map<size_t, Node>& graph,
    size_t node,
    vector<size_t>& results
) {
    unordered_set<size_t> visited;
    queue<size_t> container;
    container.push(node);

    long long pathLength = 0;
    while (!container.empty()) {
        size_t length = container.size();

        while (length > 0) {
            size_t current = container.front();
            container.pop();

            if (!visited.count(current))
            {
                results[current] = pathLength;
                for (size_t i = 1; i <= graph.size(); i++) {
                    if (i == node) {
                        continue;
                    }

                    if (!graph[current].nodes.count(i)) {
                        container.push(i);
                    }
                }

                visited.insert(current);
            }

            length--;
        }

        pathLength++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t queriesCount, nodesCount, edgesCount;
    cin >> queriesCount;

    for (size_t i = 0; i < queriesCount; i++)
    {
        cin >> nodesCount >> edgesCount;
        unordered_map<size_t, Node> graph;
        for (size_t j = 1; j <= nodesCount; j++) {
            graph[j] = {};
        }

        for (size_t j = 0; j < edgesCount; j++) {
            size_t first, second;
            std::cin >> first >> second;
            graph[first].nodes.insert(second);
            graph[second].nodes.insert(first);
        }

        size_t componentsCount = createComponents(graph);

        size_t startIndex;
        std::cin >> startIndex;

        if (componentsCount == 1) {
            vector<size_t> results(nodesCount + 1);
            calculatePathLengths(graph, startIndex, results);

            for (size_t j = 1; j <= nodesCount; j++) {
                if (j == startIndex) {
                    continue;
                }

                std::cout << results[j] << ' ';
            }
        }
        else {
            for (size_t j = 1; j <= nodesCount; j++) {
                if (j == startIndex) {
                    continue;
                }

                std::cout << (graph[startIndex].nodes.count(j) ? '2' : '1') << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}