#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

struct Edge {
    size_t from, to, weight;

    bool operator<(const Edge& rhs) const {
        return weight < rhs.weight;
    }
};

class UnionFind {
private:
    std::vector<size_t> parentsContainer;
    std::vector<size_t> sizes;

public:
    UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices) {
        for (size_t i = 0; i < vertices; i++) {
            parentsContainer[i] = i;
            sizes[i] = 1;
        }
    }

    bool areInOneSet(size_t first, size_t second) {
        return getParent(first) == getParent(second);
    }

    size_t getParent(size_t vertex) {
        if (parentsContainer[vertex] == vertex) {
            return vertex;
        }

        return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
    }

    bool unionVertices(size_t first, size_t second) {
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);

        if (parentOfFirst != parentOfSecond) {
            if (sizes[parentOfFirst] < sizes[parentOfSecond]) {
                std::swap(parentOfFirst, parentOfSecond);
            }

            // second will have lower size
            parentsContainer[parentOfSecond] = parentOfFirst;
            sizes[parentOfFirst] += sizes[parentOfSecond];
        }

        // returns if all vertices are connected
        return sizes[parentOfFirst] == sizes.size();
    }
};

struct Pair {
    size_t first, second;
};

Pair getMinMax(const std::vector<Edge>& edges, size_t verticesCount, long long index) {
    size_t min = edges[index].weight, max = LLONG_MAX;

    UnionFind ascending(verticesCount);
    while (index < edges.size() && edges[index].weight <= max) {
        auto& edge = edges[index];
        if (ascending.getParent(edge.from) != ascending.getParent(edge.to)) {
            if (ascending.unionVertices(edge.from, edge.to)) {
                max = edge.weight;
            }
        }

        index++;
    }

    return { min, max };
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<Edge> edges(edgesCount);
    for (size_t i = 0; i < edgesCount; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        --edges[i].from;
        --edges[i].to;
    }

    std::sort(edges.begin(), edges.end());

    Pair result{ LLONG_MAX, 0 };
    long long index = 0;

    while (index < edges.size())
    {
        Pair newResult = getMinMax(edges, verticesCount, index);
        size_t newResultDiff = newResult.second - newResult.first;
        size_t oldResultDiff = result.second - result.first;
        if (newResultDiff < oldResultDiff) {
            result = newResult;
        }

        while (index < edges.size() && edges[index].weight == edges[index + 1].weight) {
            index++;
        }

        index++;
    }

    std::cout << result.first << " " << result.second;

    return 0;
}