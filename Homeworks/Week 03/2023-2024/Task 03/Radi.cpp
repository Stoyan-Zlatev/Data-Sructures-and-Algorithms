#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX = 1e5 + 2;
size_t developersSkills[MAX];
size_t N, T;

bool isPossibleTeaming(size_t maxSum)
{
    size_t count = 0;
    size_t currentSum = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (developersSkills[i] > maxSum)
        {
            return false;
        }

        currentSum += developersSkills[i];
        if (currentSum > maxSum)
        {
            count++;
            currentSum = 0;
            i--;
        }
    }

    return count + 1 <= T;
}

size_t binarySearch(size_t l, size_t r)
{
    while (l <= r)
    {
        size_t mid = l + (r - l) / 2;
        if (isPossibleTeaming(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    cin >> N >> T;
    for (size_t i = 0; i < N; i++)
    {
        cin >> developersSkills[i];
    }
    cout << binarySearch(0, -1);
    return 0;
}
