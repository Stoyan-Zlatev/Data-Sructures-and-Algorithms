#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#define llong long long

using namespace std;

struct Node
{
    llong value;

    llong left;
    llong right;
};

Node tree[(size_t)4e6 + 2];

llong maxSum = LLONG_MIN;
llong getMax(llong index = 0)
{
    if (index < 0)
        return 0;

    llong nodeSum = tree[index].value;
    llong leftSum = getMax(tree[index].left);
    llong rightSum = getMax(tree[index].right);

    llong currMax = std::max({nodeSum, nodeSum + leftSum, nodeSum + rightSum});
    maxSum = std::max({maxSum, currMax, nodeSum + leftSum + rightSum});

    return currMax;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    cin >> N;

    llong value, left, right;
    for (size_t i = 0; i < N; i++)
    {
        cin >> value >> left >> right;
        tree[i] = {value, left, right};
    }
    getMax();
    cout << maxSum;
    return 0;
}
