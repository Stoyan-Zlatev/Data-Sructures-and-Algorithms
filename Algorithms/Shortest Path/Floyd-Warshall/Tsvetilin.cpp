#include <vector>
#include <climits>

void floydWarshall(size_t n)
{
    std::vector<std::vector<int64_t>> dist(n, std::vector<int64_t>(n, INT64_MAX));
    for (size_t k = 0; k < n; k++)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (dist[i][k] != INT64_MAX && dist[k][j] != INT64_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}