#include <iostream>
#include <set>

int main()
{
    size_t n;
    std::cin >> n;

    std::set<size_t> masks;
    size_t x;

    for (size_t i = 0; i <= n; ++i)
    {
        std::cin >> x;

        for (size_t m = 0; m <= x; ++m)
        {
            if ((m | x) == x)
                masks.insert(m);
        }
    }

    std::cout << masks.size();

    return 0;
}
