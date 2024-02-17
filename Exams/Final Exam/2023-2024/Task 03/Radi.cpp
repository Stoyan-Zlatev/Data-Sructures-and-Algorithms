#include <bits/stdc++.h>
using namespace std;

void dfs(size_t v, size_t parent, bool visited[], vector<size_t> g[], bool &isCycle, bool compVis[])
{
    if (visited[v] || isCycle)
    {
        isCycle = true;
        return;
    }
    visited[v] = true;
    compVis[v] = true;

    for (auto &n : g[v])
    {
        if (n != parent)
            dfs(n, v, visited, g, isCycle, compVis);
    }

    visited[v] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t T, V, E, x, y;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> V >> E;
        vector<size_t> g[1000002];
        for (size_t j = 0; j < E; j++)
        {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        size_t count = 0;
        bool compVisited[1000002]{};

        for (size_t j = 0; j < V; j++)
        {
            bool isCycle = false;
            if (!compVisited[j])
            {
                bool visited[1000002]{};
                dfs(j, j, visited, g, isCycle, compVisited);
            }
            if (isCycle)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}