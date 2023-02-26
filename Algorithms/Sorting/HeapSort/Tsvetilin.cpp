#include <vector>
#include <iostream>
#include <algorithm>

void heapify(std::vector<size_t> &arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<size_t> &arr)
{
    size_t n = arr.size();
    for (size_t i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (size_t i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}