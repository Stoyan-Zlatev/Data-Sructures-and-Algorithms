#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> ivan(n);
    std::vector<size_t> brat(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> ivan[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> brat[i];
    }

    size_t count = 0;
    std::unordered_map<size_t, size_t> current;
    for (size_t i = 0; i < n; i++)
    {
        current[ivan[i]]++;

        if (current[brat[i]] == 0)
        {
            count++;
        }
        else
        {
            current[brat[i]]--;
        }
    }

    std::cout << count;
    return 0;
}