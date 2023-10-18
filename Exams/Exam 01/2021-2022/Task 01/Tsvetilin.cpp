#include <vector>
#include <iostream>
#include <algorithm>

typedef double dataType;
typedef std::vector<dataType> list;

bool cmpData(dataType &first, dataType &second)
{
    return first < second;
}

int partition(list &data, int left, int right)
{
    dataType pivot = data[right];
    int partitionIndex = left;

    for (size_t i = left; i < right; ++i)
    {
        if (cmpData(data[i], pivot))
            std::swap(data[i], data[partitionIndex++]);
    }

    std::swap(data[right], data[partitionIndex]);
    return partitionIndex;
}

void quickSort(list &data, int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition(data, left, right);

    quickSort(data, left, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, right);
}

int main()
{
    int n;
    std::cin >> n;

    list data(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> data[i];
    }

    std::swap(data[n - 1], data[n / 2]);

    quickSort(data, 0, n - 1);

    dataType last = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (data[i] != last)
            std::cout << data[i] << " ";

        last = data[i];
    }
}