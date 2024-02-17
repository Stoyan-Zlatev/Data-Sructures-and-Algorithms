#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t T, X, N;
const size_t MAX = 5 * (1e4) + 2;

struct BoxData
{
    size_t wi;
    size_t ind;
};
BoxData boxData[MAX];

void binarySearch(size_t &l, size_t &r)
{
    while (l <= r)
    {
        if ((boxData[l].wi + boxData[r].wi) < X)
        {
            l++;
            continue;
        }
        else if ((boxData[l].wi + boxData[r].wi) > X)
        {
            r--;
            continue;
        }
        break;
    }
}

int main()
{
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> X;
        cin >> N;

        for (size_t i = 0; i < N; i++)
        {
            size_t n;
            cin >> n;
            boxData[i] = {n, i + 1};
        }
        sort(boxData, boxData + N, [](auto &a, auto &b)
             { return a.wi <= b.wi; });

        size_t l = 0;
        size_t r = N - 1;
        binarySearch(l, r);
        if (boxData[r].ind <= boxData[l].ind)
        {
            cout << boxData[r].ind << " " << boxData[l].ind << '\n';
        }
        else
        {
            cout << boxData[l].ind << " " << boxData[r].ind << '\n';
        }
    }
    return 0;
}