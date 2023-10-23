#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX = 1e4 + 2;
size_t input[MAX];

int main()
{
    size_t N, K;
    cin >> N >> K;

    for (size_t i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input, input + N);

    size_t minDif = -1;
    for (size_t i = 0; i < N - K + 1; i++)
    {
        if (input[i + K - 1] - input[i] <= minDif)
        {
            minDif = input[i + K - 1] - input[i];
        }
    }

    cout << minDif;
    return 0;
}