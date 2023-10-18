#include <iostream>
#include <deque>
#include <climits>
#include <algorithm>

int main()
{
    size_t n, k;

    std::cin >> n >> k;

    long long x;
    std::deque<long long> deq;
    long long minElement = LLONG_MAX;

    for (size_t i = 0; i < k; ++i)
    {
        std::cin >> x;
        deq.emplace_back(x);
        minElement = std::min(x, minElement);
    }

    long long sum = minElement;

    for (size_t i = 0; i < n - k; ++i)
    {
        long long last = deq.front();
        deq.pop_front();

        std::cin >> x;
        deq.emplace_back(x);

        if (x < minElement)
        {
            minElement = x;
        }
        else if (last == minElement)
        {
            minElement = deq[0];
            for (size_t i = 1; i < k; ++i)
            {
                minElement = std::min(deq[i], minElement);
            }
        }

        sum += minElement;
    }

    std::cout << sum;

    return 0;
}
