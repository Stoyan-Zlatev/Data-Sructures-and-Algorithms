#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    size_t N, Q;
    cin >> N;
    cin >> Q;
    vector<size_t> input(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());
    for (size_t i = 0; i < Q; i++)
    {
        size_t qiS, qiE;
        cin >> qiS >> qiE;
        if (qiS > qiE)
        {
            cout << 0 << '\n';
            continue;
        }

        auto low = lower_bound(input.begin(), input.end(), qiS);
        long long startInd = low - input.begin();
        auto upp = upper_bound(input.begin(), input.end(), qiE);
        long long endInd = upp - input.begin() - 1;
        cout << endInd - startInd + 1 << '\n';
    }

    return 0;
}
