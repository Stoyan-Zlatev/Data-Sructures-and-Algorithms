#include <vector>
#include <algorithm>

// TODO: change data type
typedef int dataType;
typedef std::vector<dataType> list;

// TODO: handle objects comparison
bool cmpData(dataType &first, dataType &second)
{
    return true;
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