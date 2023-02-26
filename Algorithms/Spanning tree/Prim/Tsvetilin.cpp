#include <queue>
#include <vector>

struct Edge
{
    long long from;
    long long to;
    long long weight;

    bool operator<(const Edge &other) const
    {
        return weight > other.weight;
    }
};

long long prim(std::vector<std::vector<Edge>> &graph)
{
    long long result = 0;
    std::vector<bool> visited(graph.size(), false);

    std::priority_queue<Edge> nextToProcess;
    nextToProcess.push({0, 0, 0});
    long long edges = 0;

    while (!nextToProcess.empty() && edges < graph.size() - 1)
    {
        auto toProcess = nextToProcess.top();
        nextToProcess.pop();
        
        // This is the node of the tree
        long long current = toProcess.to;
        visited[current] = true;
        result += toProcess.weight;
        edges++;

        for (auto &neighbour : graph[current])
        {
            if (!visited[neighbour.to])
            {
                nextToProcess.push({current, neighbour.to, neighbour.weight});
            }
        }
    }

    return result;
}