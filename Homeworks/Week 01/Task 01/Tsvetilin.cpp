#include <iostream>

int main()
{
    size_t q;
    std::string input;
    size_t length;
    size_t counter;

    std::cin >> q;

    for (size_t i = 0; i < q; ++i)
    {
        std::cin >> length;
        std::cin >> input;

        counter = 0;

        for (size_t i = 1; i < length; ++i)
        {
            if (input[i] == input[i - 1])
            {
                ++counter;
            }
        }

        std::cout << counter << std::endl;
    }
}