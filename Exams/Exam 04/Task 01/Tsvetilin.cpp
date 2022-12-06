#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct interval
{
    size_t start;
    size_t end;

    bool operator<(const interval &other) const
    {
        return start > other.start;
    }

    bool operator>(const interval &other) const
    {
        return end > other.end;
    }
};

int main()
{

    std::priority_queue<interval, std::vector<interval>, std::less<interval>> orderByStart;
    std::priority_queue<interval, std::vector<interval>, std::greater<interval>> orderByEnd;

    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        interval il;
        std::cin >> il.start >> il.end;

        if (il.start < il.end)
        {
            orderByStart.push(il);
        }
    }

    size_t end = 0;
    size_t maxEl = 0;

    while (!orderByStart.empty())
    {
        end = orderByStart.top().start;
        orderByEnd.push(orderByStart.top());
        orderByStart.pop();

        while (!orderByEnd.empty() && orderByEnd.top().end <= end)
        {
            orderByEnd.pop();
        }

        maxEl = std::max(maxEl, orderByEnd.size());
    }

    std::cout << maxEl;

    return 0;
}
