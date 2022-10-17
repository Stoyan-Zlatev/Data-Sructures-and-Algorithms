#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

void bubbleSort(list &data, int left, int right)
{

    for (size_t i = left; i <= right; i++)
    {
        bool hasSwapped = false;
        for (size_t j = left; j < right - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                hasSwapped = true;
                std::swap(data[j], data[j + 1]);
            }
        }

        if (!hasSwapped)
            return;
    }
}