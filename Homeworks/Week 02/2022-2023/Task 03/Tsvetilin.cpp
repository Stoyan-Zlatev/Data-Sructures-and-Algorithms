#include <iostream>
#include <vector>
#include <algorithm>

const unsigned char MAX_SIZE = -1;

int indexes[MAX_SIZE]{};

int main()
{
    std::string input;

    std::cin >> input;
    size_t length = input.length();

    for (size_t i = 0; i < length; i++)
    {
        if (indexes[input[i]] == 0)
        {
            indexes[input[i]] = i + 1;
        }
        else if (indexes[input[i]] > 0)
        {
            indexes[input[i]] = -1;
        }
    }

    std::vector<int> result;
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        if ((indexes[i] - 1) > 0)
        {
            result.push_back(indexes[i] - 1);
        }
    }

    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
}