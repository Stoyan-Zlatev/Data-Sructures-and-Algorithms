#include <iostream>
#include <vector>

void task1()
{
    size_t n;

    std::cin >> n;
    std::vector<short> even;
    std::vector<short> odd;
    for (size_t i = 0; i < n; i++) {
        short inputNumber;
        std::cin >> inputNumber;
        if (inputNumber % 2 == 0)
            even.push_back(inputNumber);
        else
            odd.push_back(inputNumber);
    }

    for (size_t i = 0; i < even.size(); i++)
        std::cout << even[i] << "\n";
    for (size_t i = 0; i < odd.size(); i++)
        std::cout << odd[i] << "\n";
}