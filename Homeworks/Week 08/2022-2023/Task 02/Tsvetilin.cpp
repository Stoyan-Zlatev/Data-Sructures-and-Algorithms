#include <iostream>
#include <queue>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    size_t n;
    std::cin >> n;

    std::priority_queue<size_t, std::vector<size_t>, std::less<size_t>> leftHalf;
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> rightHalf;

    long double median = 0;
    size_t x;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;

        if (x < median)
            leftHalf.push(x);
        else
            rightHalf.push(x);

        if (leftHalf.size() > rightHalf.size() + 1)
        {
            rightHalf.push(leftHalf.top());
            leftHalf.pop();
        }

        if (rightHalf.size() > leftHalf.size() + 1)
        {
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }

        if (i % 2 == 0)
        {
            median = rightHalf.size() > leftHalf.size() ? rightHalf.top() : leftHalf.top();
        }
        else
        {
            median = (rightHalf.top() + leftHalf.top()) / 2.0;
        }

        std::cout << median << "\n";
    }

    return 0;
}