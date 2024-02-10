#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    long long left;
    long long right;

    long long leftCount;
    long long rightCount;
};

Node tree[1000000];

void dfs(long long rootIndex = 0)
{
    if (rootIndex == -1)
        return;

    long long leftInd = tree[rootIndex].left;
    long long rightInd = tree[rootIndex].right;

    dfs(leftInd);
    dfs(rightInd);

    if (leftInd != -1)
    {
        tree[rootIndex].leftCount = 1 + tree[leftInd].leftCount + tree[leftInd].rightCount;
    }
    if (rightInd != -1)
    {
        tree[rootIndex].rightCount = 1 + tree[rightInd].leftCount + tree[rightInd].rightCount;
    }
}

int main()
{
    size_t N;
    cin >> N;
    long long left, right;
    for (size_t i = 0; i < N; i++)
    {
        cin >> left >> right;
        tree[i] = {left, right, 0, 0};
    }
    dfs();
    long long uppCount;
    long long maxProduct = 0;
    for (size_t i = 0; i < N; i++)
    {
        long long leftC = tree[i].leftCount;
        long long rightC = tree[i].rightCount;
        uppCount = N - leftC - rightC - 1;
        uppCount = uppCount == 0 ? 1 : uppCount;
        leftC = leftC == 0 ? 1 : leftC;
        rightC = rightC == 0 ? 1 : rightC;
        maxProduct = max(maxProduct, leftC * rightC * uppCount);
    }
    cout << maxProduct;

    return 0;
}