#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const size_t MAX_SIZE = 1e6;
size_t input[MAX_SIZE];

int main()
{
    long long N;
    size_t D;
    cin >> N >> D;
    for (long long i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    size_t counter = 0;
    sort(input, input + N);
    long long i = 0;
    long long j = 0;
    while (i <= N - 1 && j <= N - 1)
    {
        if (input[j] - input[i] == D)
        {
            counter++;
            i++;
            j++;
        }
        else if (input[j] - input[i] < D)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << counter;
    return 0;
}