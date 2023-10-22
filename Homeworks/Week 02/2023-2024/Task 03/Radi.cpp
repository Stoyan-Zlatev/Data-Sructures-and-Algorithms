#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX_N = 1e5 + 2;

struct Data
{
    size_t diameter;
    size_t time;
    double efficiency;
    size_t index;
};

int main()
{
    size_t N;
    cin >> N;
    Data d[MAX_N];
    size_t diameter;
    size_t time;

    for (size_t i = 0; i < N; i++)
    {
        cin >> diameter;
        cin >> time;
        d[i] = {diameter, time, (double)(diameter * diameter) / time, i + 1};
    }

    sort(d, d + N, [](auto &a, auto &b)
         { return a.efficiency == b.efficiency ? a.area > b.area : a.efficiency > b.efficiency; });

    for (size_t i = 0; i < N; i++)
    {
        std::cout << d[i].index << " ";
    }

    return 0;
}
