#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_set>

long long bfs(std::vector<std::vector<size_t>>& graph, size_t from, size_t to, std::unordered_set<size_t>& shouldNotVisit) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<size_t> toVisit;
    toVisit.push(from);

    long long result = -1;
    long long currentLength = 0;
    while (!toVisit.empty()) {
        size_t length = toVisit.size();

        while (length > 0) {
            size_t current = toVisit.front();
            toVisit.pop();

            visited[current] = true;
            if (current == to) {
                result = currentLength;
                break;
            }

            for (size_t i = 0; i < graph[current].size(); i++) {
                if (visited[graph[current][i]] || shouldNotVisit.count(current)) {
                    continue;
                }

                toVisit.push(graph[current][i]);
            }

            length--;
        }

        if (result != -1) {
            break;
        }
        currentLength++;
    }

    return result;
}

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<std::vector<size_t>> graph(verticesCount);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
    }

    size_t attractionsCount;
    std::cin >> attractionsCount;
    std::vector<size_t> attractions(attractionsCount);
    std::unordered_set<size_t> shouldNotVisit;

    for (size_t i = 0; i < attractionsCount; i++) {
        std::cin >> attractions[i];
        shouldNotVisit.insert(attractions[i]);
    }

    long long totalPath = 0;
    shouldNotVisit.erase(attractions[0]);
    for (size_t i = 1; i < attractionsCount; i++) {
        shouldNotVisit.erase(attractions[i]);
        long long pathLength = bfs(graph, attractions[i - 1], attractions[i], shouldNotVisit);

        if (pathLength == -1) {
            totalPath = -1;
            break;
        }

        totalPath += pathLength;
    }

    std::cout << totalPath;

    return 0;
}