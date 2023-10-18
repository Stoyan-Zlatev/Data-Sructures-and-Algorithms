#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

void createShortestPaths(long long graph[400][400], long long nodesCount) {
    for (long long i = 0; i < nodesCount; i++) {
        for (long long j = 0; j < nodesCount; j++) {
            for (long long k = 0; k < nodesCount; k++) {
                long long alternativeLength = graph[j][i] + graph[i][k];
                if (graph[j][k] > alternativeLength && (graph[j][i] != LLONG_MAX && graph[i][k] != LLONG_MAX)) {
                    graph[j][k] = alternativeLength;
                }
            }
        }
    }
};

long long graph[400][400];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long nodesCount, edgesCount, queriesCount;
    std::cin >> nodesCount >> edgesCount >> queriesCount;

    // set values
    for (long long i = 0; i < nodesCount; i++) {
        for (long long j = 0; j < nodesCount; j++) {
            graph[i][j] = (i != j ? LLONG_MAX : 0);
        }
    }

    // read graph
    for (long long i = 0; i < edgesCount; i++) {
        long long first, second, weight;
        std::cin >> first >> second >> weight;
        if (graph[first][second] > weight) {
            graph[first][second] = weight;
        }
    }

    // create paths
    createShortestPaths(graph, nodesCount);

    // print results
    for (long long i = 0; i < queriesCount; i++) {
        long long first, second;
        std::cin >> first >> second;
        std::cout << (graph[first][second] == LLONG_MAX ? -1 : graph[first][second]) << '\n';
    }

    return 0;
}