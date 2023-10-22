#include <algorithm>
#include <iostream>
#include <vector>

const size_t MAX_SIZE = 1e5;

size_t arr[MAX_SIZE]{};
std::vector<size_t> sortedArr(MAX_SIZE);

size_t sum;

bool checkPossiblePartitions(size_t count, size_t partitions, size_t target)
{
    if (std::upper_bound(sortedArr.begin(), sortedArr.begin() + count, target) - sortedArr.begin() < count)
    {
        return false;
    }

    size_t currentSum = 0;
    for (size_t i = 0; i < count; i++)
    {
        currentSum += arr[i];
        if (currentSum > target)
        {
            --partitions;

            if (partitions == 0 && i <= count - 1)
                return false;

            currentSum = 0;

            if (i == count - 1)
                break;

            --i;
        }
    }

    return true;
}

size_t binary(size_t left, size_t right, size_t count, size_t partitions)
{
    size_t result = left;

    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;

        if (checkPossiblePartitions(count, partitions, mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

int main()
{
    size_t n, t;
    std::cin >> n >> t;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        sortedArr[i] = arr[i];
         sum += arr[i];
    }

    std::sort(sortedArr.begin(), sortedArr.begin() + n);

    for (size_t i = 0; i < n; i++)
    {
        size_t current = 0;
        for (size_t j = 0; j < n; j++)
        {
            current += j;
        }
    }

    std::cout << binary(sortedArr[n - 1], sum, n, t);
}