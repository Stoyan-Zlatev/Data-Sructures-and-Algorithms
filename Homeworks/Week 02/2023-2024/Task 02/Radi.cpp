#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define llong long long

using namespace std;

const size_t MAX_SIZE = 1e7 + 2;
long long profits[MAX_SIZE];

int main()
{
    llong N;
    cin >> N;

    for (llong i = 0; i < N; i++)
    {
        cin >> profits[i];
    }

    llong l = 0;
    llong r = N - 1;

    while (l < N - 1 && profits[l + 1] >= profits[l])
    {
        l++;
    }
    while (r > 0 && profits[r] >= profits[r - 1])
    {
        r--;
    }

    if (l >= r)
    {
        cout << 0;
        return 0;
    }

    llong minEl = profits[l];
    llong maxEl = profits[l];

    for (llong i = l; i <= r; i++)
    {
        minEl = min(minEl, profits[i]);
        maxEl = max(maxEl, profits[i]);
    }

    llong lFind = l;
    llong rFind = r;
    while (lFind >= 0 && profits[lFind] > minEl)
    {
        lFind--;
    }

    while (rFind <= N - 1 && profits[rFind] < maxEl)
    {
        rFind++;
    }

    cout << rFind - lFind - 1;

    return 0;
}
