#include <iostream>

const size_t MAX_SIZE = 1e5;

int main()
{
    size_t count;
    size_t arr[MAX_SIZE];

    std::cin >> count;

    for (size_t i = 0; i < count; ++i)
    {
        std::cin >> arr[i];
    }

    int currentMinInd = 0;
    int currentMaxInd = 0;
    int sum = 0;

    for (size_t i = 1; i < count; i++)
    {
        if (arr[currentMaxInd] < arr[i])
        {
            currentMaxInd = i;
        }
        else if (arr[i] < arr[currentMaxInd])
        {
            sum += (arr[currentMaxInd] - arr[currentMinInd]);
            currentMaxInd = currentMinInd = i;
        }
        else if (arr[i] < arr[currentMinInd])
        {
            currentMaxInd = currentMinInd = i;
        }
    }

    if (arr[currentMaxInd] - arr[currentMinInd] > 0)
    {
        sum += (arr[currentMaxInd] - arr[currentMinInd]);
    }

    std::cout << sum;
}