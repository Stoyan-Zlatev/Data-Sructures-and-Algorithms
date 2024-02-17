#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    vector<long long> children;
    size_t countChildren = 0;
};

Node tree[(size_t)1e6 + 2];

void dfs(size_t ind)
{
    for (auto &child : tree[ind].children)
    {
        dfs(child);
        tree[ind].countChildren += tree[child].countChildren + 1;
    }
}

size_t N;

int main()
{
    cin >> N;
    long long parent, child;
    while (cin >> parent >> child)
    {
        tree[parent].children.push_back(child);
    }
    dfs(0);
    for (size_t i = 0; i < N; i++)
    {
        cout << tree[i].countChildren << " ";
    }
    return 0;
}
