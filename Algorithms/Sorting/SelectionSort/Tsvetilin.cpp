#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

void selectionSort(list &data, int left, int right)
{
    for (size_t i = left; i < right; i++)
    {
        int minIndex = i;
        for (size_t j = left + 1; j <= right; j++)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
            std::swap(data[i], data[minIndex]);
    }
}