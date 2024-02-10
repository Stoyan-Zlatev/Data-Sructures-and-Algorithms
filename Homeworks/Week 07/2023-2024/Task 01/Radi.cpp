#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, B;
    cin >> N >> B;

    long long arr[10000006];

    long long indSearched = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == B)
            indSearched = i;
    }

    long long res = 0;
    map<long long, long long> count;

    int balance = 0;
    for (long long i = indSearched; i >= 0; i--)
    {
        if (arr[i] < B)
            balance--;
        else if (arr[i] > B)
            balance++;
        count[balance]++;
    }

    balance = 0;
    for (long long i = indSearched; i < N; i++)
    {
        if (arr[i] < B)
            balance--;
        else if (arr[i] > B)
            balance++;
        res += count[-balance];
    }

    cout << res;
    return 0;
}
