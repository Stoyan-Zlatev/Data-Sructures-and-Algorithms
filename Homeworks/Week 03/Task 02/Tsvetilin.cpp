#include <iostream>
#include <algorithm>

const long long MAX_N = 1e6;
long long weights[MAX_N]{};

int main()
{
    long long n;
    long long q;
    std::cin >> n >> q;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> weights[i];
    }

    std::sort(weights, weights + n);

    long long min, max;
    for (size_t i = 0; i < q; i++)
    {
        std::cin >> min >> max;

        std::cout << (std::upper_bound(weights, weights + n, max) - std::lower_bound(weights, weights + n, min)) << std::endl;
    }
}