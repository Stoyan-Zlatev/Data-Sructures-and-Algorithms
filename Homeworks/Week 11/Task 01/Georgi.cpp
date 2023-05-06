#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

struct Pair {
    int index;
    int distance;

    Pair(int index, int distance)
        : index(index), distance(distance) { }

    bool operator<(const Pair& rhs) const {
        return distance > rhs.distance;
    }
};

struct Node {
    int interval;
    std::vector<Pair> neightbours;
};

long long shortestPath(std::vector<Node>& graph, int start, int end) {
    std::vector<int> previous(graph.size(), -1);
    std::vector<long long> distance(graph.size(), INT_MAX);
    //std::vector<bool> visited(graph.size(), false);

    distance[start] = 0;

    std::priority_queue<Pair> nextToProcess;
    nextToProcess.push({ start, 0 });

    while (!nextToProcess.empty()) {
        Pair toProcess = nextToProcess.top();
        nextToProcess.pop();

        int current = toProcess.index;

        for (auto& neighbour : graph[current].neightbours) {
            long long alternativeDistance = distance[current] + neighbour.distance;
            if (distance[current] % graph[current].interval != 0) {
                alternativeDistance += (graph[current].interval - distance[current] % graph[current].interval);
            }

            if (alternativeDistance <= distance[neighbour.index]) {
                distance[neighbour.index] = alternativeDistance;
                previous[neighbour.index] = toProcess.index;
                nextToProcess.push(neighbour);
            }
        }
    }

    return previous[end] == -1 ? -1 : distance[end];
};

int main() {
    int nodesCount, edgesCount, start, end;
    std::cin >> nodesCount >> edgesCount >> start >> end;

    std::vector<Node> graph(nodesCount);

    for (int i = 0; i < nodesCount; i++) {
        int interval;
        std::cin >> interval;
        graph[i].interval = interval;
    }

    for (int i = 0; i < edgesCount; i++) {
        int first, second, weight;
        std::cin >> first >> second >> weight;
        graph[first].neightbours.push_back(Pair(second, weight));
    }

    std::cout << shortestPath(graph, start, end);

    return 0;
}