#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>

const int MOD = 1e9 + 7;

struct Pair {
    long long index;
    long long distance;

    Pair(long long index, long long distance)
        : index(index), distance(distance) { }

    bool operator<(const Pair& rhs) const {
        return distance > rhs.distance;
    }
};

long long shotestPathToEnd(std::vector<std::vector<Pair>>& graph, long long start, long long end) {
    std::vector<long long> distance(graph.size(), LLONG_MAX);
    std::vector<long long> paths(graph.size(), 0);

    distance[start] = 0;
    paths[start] = 1;
    std::priority_queue<Pair> nextToProcess;
    nextToProcess.push({ start, 0 });

    while (!nextToProcess.empty()) {
        Pair toProcess = nextToProcess.top();
        nextToProcess.pop();

        long current = toProcess.index;

        if (toProcess.distance > distance[current]) {
            continue;
        }

        for (auto& neighbour : graph[current]) {
            long long alternativeDistance = distance[current] + neighbour.distance;

            if (alternativeDistance < distance[neighbour.index]) {
                distance[neighbour.index] = alternativeDistance;
                nextToProcess.push({neighbour.index, alternativeDistance});
            }

            if (distance[current] < distance[neighbour.index]) {
                paths[neighbour.index] += paths[current];
                paths[neighbour.index] %= MOD;
            }
        }
    }

    return paths[end];
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long nodesCount, edgesCount, start, end;
    std::cin >> nodesCount >> edgesCount >> start >> end;

    std::vector<std::vector<Pair>> graph(nodesCount);

    for (long long i = 0; i < edgesCount; i++) {
        long long first, second, weight;
        std::cin >> first >> second >> weight;
        graph[first].push_back(Pair(second, weight));
        graph[second].push_back(Pair(first, weight));
    }

    // end to start to track increasing min paths
    std::cout << shotestPathToEnd(graph, end, start);

    return 0;
}