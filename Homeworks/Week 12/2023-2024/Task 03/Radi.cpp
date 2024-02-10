#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const size_t MAX = 1e4 + 2;
size_t parent[MAX];
size_t depht[MAX];

struct Vertex
{
    size_t from;
    size_t to;
    size_t optimalSpeed;

    bool operator<(const Vertex &other) const
    {
        return optimalSpeed < other.optimalSpeed;
    }
};

size_t findParent(size_t v)
{
    if (v == parent[v])
    {
        return v;
    }
    return findParent(parent[v]);
}

void unionVert(size_t from, size_t to)
{

    if (depht[from] < depht[to])
    {
        parent[from] = to;
    }
    else
    {
        parent[to] = from;
        if (depht[from] == depht[to])
        {
            depht[from]++;
        }
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;
    Vertex edges[MAX];
    size_t fi, ti, speedi;
    for (size_t i = 0; i < M; i++)
    {
        cin >> fi >> ti >> speedi;
        edges[i] = {fi, ti, speedi};
    }

    sort(edges, edges + M, less<Vertex>());
    size_t minSpeed = 0;
    size_t maxSpeed = -1;
    for (size_t i = 0; i < M; i++)
    {

        for (size_t j = 0; j <= N; j++)
        {
            parent[j] = j;
            depht[j] = 0;
        }
        size_t count = 0;
        size_t currentMin = edges[i].optimalSpeed;
        size_t currentMax = edges[i].optimalSpeed;
        size_t diff = maxSpeed - minSpeed;
        for (size_t j = i; j < M; j++)
        {

            size_t vert1 = findParent(edges[j].from);
            size_t vert2 = findParent(edges[j].to);
            unionVert(vert1, vert2);
            if (vert1 != vert2)
            {
                count++;
                currentMax = max(currentMax, edges[j].optimalSpeed);
            }

            if (diff <= currentMax - currentMin)
                break;
        }

        if (count != N - 1 || diff <= currentMax - currentMin)
            continue;

        minSpeed = currentMin;
        maxSpeed = currentMax;
    }

    cout << minSpeed << " " << maxSpeed;

    return 0;
}
