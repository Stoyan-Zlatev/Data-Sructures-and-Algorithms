#include <iostream>
#include <algorithm>
#include <cmath>

const size_t MAX_SIZE = 1e5;
size_t arr[MAX_SIZE];
size_t result[MAX_SIZE];

int binary(size_t *start, size_t *end, size_t search)
{
    size_t *originalStart = start;

    while (start <= end)
    {
        size_t *mid = start + (size_t)(end - start) / 2;

        if (*mid == search)
            return mid - start;

        if (*mid < search)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

void ternary(size_t left, size_t right, size_t n, size_t i = 1)
{
    if (left >= right && left < n)
    {
        int ind = binary(arr, arr + n, left);
        if (ind != -1)
        {
            result[ind] = i;
        }

        return;
    }

    size_t mid1 = left + (right - left) / 3;
    size_t mid2 = right - (right - left) / 3;

    ternary(left, mid1 - 1, n, i + 1);

    
    for (size_t i = mid1; i < mid2; i++)
    {
        int ind = binary(arr, arr + n, left);
        if (ind != -1)
        {
            result[ind] = i;
        }
    }

    ternary(mid2 + 1, right, n, i + 1);
}

int main()
{
    int n, p;
    std::cin >> p >> n;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    ternary(1, pow(3,p), n);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << result[i] << " ";
    }
}