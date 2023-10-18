#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

int main()
{
    std::unordered_map<size_t, long long> q;

    size_t n;
    std::cin >> n;

    size_t x;
    std::vector<size_t> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;
        q.insert({x, -1});
        nums[i] = x;
    }

    long long startIndex = 0;
    long long maxSize = LLONG_MIN;

    long long i = 0;
    for (; i < n; i++)
    {
        while (q[nums[i]] >= startIndex)
        {
            maxSize = std::max(maxSize, i - startIndex);
            startIndex++;
        }

        q[nums[i]] = i;
    }

    maxSize = std::max(maxSize, i - startIndex);

    std::cout << maxSize;

    return 0;
}