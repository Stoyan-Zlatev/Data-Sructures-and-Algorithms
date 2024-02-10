#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    size_t N;
    cin >> N;
    unordered_map<size_t, vector<size_t>> m;

    size_t temp;
    for (size_t i = 0; i < N; i++)
    {
        cin >> temp;
        m[temp].push_back(i);
    }

    size_t minDist = -1;
    for (auto &iter : m)
    {
        if (iter.second.size() < 2)
        {
            continue;
        }

        for (size_t i = 0; i < iter.second.size() - 1; i++)
        {
            minDist = min(minDist, iter.second[i + 1] - iter.second[i]);
        }
    }

    cout << minDist;

    return 0;
}
