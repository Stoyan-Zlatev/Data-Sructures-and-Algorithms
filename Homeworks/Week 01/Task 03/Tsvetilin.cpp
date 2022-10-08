#include <iostream>

const size_t MAX_NUM_SIZE = 1e6 + 2;
bool check[MAX_NUM_SIZE];

int main()
{
    size_t n;
    std::cin >> n;

    long long input;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        if (input > 0 && input < MAX_NUM_SIZE)
        {
            check[input] = true;
        }
    }

    for (size_t i = 1; i < MAX_NUM_SIZE; i++)
    {
        if (!check[i])
        {
            std::cout << i;
            break;
        }
    }
}