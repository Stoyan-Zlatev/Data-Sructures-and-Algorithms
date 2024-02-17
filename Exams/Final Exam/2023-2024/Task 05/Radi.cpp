#include <bits/stdc++.h>
using namespace std;

vector<long long> tree[10000002];
bool colored[10000002];
size_t parent[10000002];

void dfs(size_t node, size_t &count)
{
    for (auto &n : tree[node])
    {
        dfs(n, count);
    }

    if (!colored[node])
    {
        count++;
        colored[node] = true;

        colored[parent[node]] = true;

        for (auto &n : tree[parent[node]])
        {
            colored[n] = true;
        }

        colored[parent[parent[node]]] = true;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N;
    cin >> N;
    long long left, right;
    for (size_t i = 0; i < N; i++)
    {
        cin >> left >> right;
        if (left != -1)
        {
            tree[i].push_back(left);
            parent[left] = i;
        }
        if (right != -1)
        {
            tree[i].push_back(right);
            parent[right] = i;
        }
    }
    size_t count = 0;
    dfs(0, count);
    cout << count;

    return 0;
}