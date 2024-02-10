#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
size_t N;
const size_t MAX = 1e6 + 2;

long long posSumsOffset[MAX]{};
long long negSumsOffset[MAX]{};
stack<long long> negSumsOffsetInOrder;

struct Node
{
    long long key;

    long long left;
    long long right;

    long long xOffset;
};

Node tree[MAX];

void dfs(long long indexInTree = 0, long long xOffset = 0)
{
    if (indexInTree == -1)
        return;

    if (xOffset < 0)
    {
        negSumsOffset[-xOffset] += tree[indexInTree].key;
    }
    if (xOffset >= 0)
    {
        posSumsOffset[xOffset] += tree[indexInTree].key;
    }
    tree[indexInTree].xOffset = xOffset;
    dfs(tree[indexInTree].left, xOffset - 1);
    dfs(tree[indexInTree].right, xOffset + 1);
}

void printAllSums()
{
    size_t startIndNeg = 1;
    while (negSumsOffset[startIndNeg] != 0)
    {
        negSumsOffsetInOrder.push(negSumsOffset[startIndNeg]);
        startIndNeg++;
    }
    while (!negSumsOffsetInOrder.empty())
    {
        cout << negSumsOffsetInOrder.top() << " ";
        negSumsOffsetInOrder.pop();
    }

    size_t startIndPos = 0;
    while (posSumsOffset[startIndPos] != 0)
    {
        cout << posSumsOffset[startIndPos] << " ";
        startIndPos++;
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        long long key, left, right;
        cin >> key >> left >> right;
        tree[i] = {key, left, right};
    }

    dfs();
    printAllSums();
    return 0;
}
