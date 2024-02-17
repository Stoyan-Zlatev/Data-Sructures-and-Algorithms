#include <bits/stdc++.h>
using namespace std;

size_t findParent(size_t v, size_t parent[])
{
    if (v == parent[v])
        return parent[v];
    return parent[v] = findParent(parent[v], parent);
}

void dfs(size_t v, pair<size_t, size_t> components[], bool visited[], unordered_map<size_t, size_t> g[], size_t index)
{

    visited[v] = true;
    for (auto &n : g[v])
    {
        size_t neighbour = n.first;
        size_t cost = n.second;

        if (!visited[neighbour])
        {
            components[index].first++;
            components[index].second += cost;
            dfs(neighbour, components, visited, g, index);
        }
    }
}
void unionV(size_t l, size_t r, size_t parent[], size_t depth[])
{
    if (depth[l] < depth[r])
    {
        parent[l] = r;
    }

    else
    {
        parent[r] = l;
        if (depth[l] == depth[r])
        {
            depth[l]++;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t T, V, E, K, x, y, w;
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        unordered_map<size_t, size_t> g[50002];
        vector<pair<pair<size_t, size_t>, size_t>> edges;
        size_t parent[50002];
        size_t depht[50002];
        cin >> V >> E >> K;
        for (size_t j = 0; j < E; j++)
        {
            cin >> x >> y >> w;
            edges.push_back({{x, y}, w});
        }
        sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2)
             { return e1.second < e2.second; });

        for (size_t j = 0; j < V; j++)
        {
            parent[j] = j;
            depht[j] = 0;
        }

        for (size_t k = 0; k < E; k++)
        {
            size_t parentV = findParent(edges[k].first.first, parent);
            size_t parentW = findParent(edges[k].first.second, parent);
            if (parentV != parentW)
            {
                g[edges[k].first.first][edges[k].first.second] = edges[k].second;
                g[edges[k].first.second][edges[k].first.first] = edges[k].second;
                unionV(parentV, parentW, parent, depht);
            }
        }
        pair<size_t, size_t> components[50002];
        bool visited[50002]{};
        size_t index = 0;
        for (size_t j = 0; j < V; j++)
        {
            if (!visited[j])
            {
                dfs(j, components, visited, g, index);
                index++;
            }
        }

        size_t count = 0;
        for (size_t j = 0; j < index; j++)
        {
            if ((components[j].first + 1) % K == 0)
            {
                count += components[j].second;
            }
        }
        cout << count << endl;
    }
    return 0;
}