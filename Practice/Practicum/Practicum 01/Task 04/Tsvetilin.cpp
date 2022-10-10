#include <iostream>

int main()
{
    size_t t;

    std::cin >> t;

    size_t n, m;

    for (size_t i = 0; i < t; i++)
    {
        std::cin >> n >> m;
        m--;
        if ((m > 0 && n >= m && (n - m) % 2 == 0) || (m == 0 && n == 0))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}