#include <iostream>

const size_t MAX_LEN = 1e7 + 1;
char input[MAX_LEN]{};

int main()
{
    std::cin >> input;

    size_t i = 0;
    size_t count = 0;
    char currentLetter = input[0];

    while (input[i])
    {
        if (currentLetter == input[i])
        {
            ++count;
        }
        else
        {
            std::cout << count << currentLetter;
            currentLetter = input[i];
            count = 1;
        }

        ++i;
    }

    std::cout << count << currentLetter;
}
