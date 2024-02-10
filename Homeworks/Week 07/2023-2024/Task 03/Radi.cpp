#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t Q;
    cin >> Q;
    set<size_t> s;
    s.insert(0);

    size_t minXOR = -1;
    for (size_t i = 0; i < Q; i++)
    {
        size_t num;
        cin >> num;

        auto res = s.insert(num);

        if (!res.second)
        {
            cout << minXOR << endl;
            continue;
        }
        auto currIt = res.first;
        size_t leftXOR = minXOR;
        size_t rightXOR = minXOR;

        if (currIt != s.begin())
        {
            leftXOR = num ^ *prev(currIt);
        }
        if (currIt != --s.end())
        {
            rightXOR = num ^ *next(currIt);
        }
        minXOR = min({leftXOR, rightXOR, minXOR});
        cout << minXOR << endl;
    }
    return 0;
}