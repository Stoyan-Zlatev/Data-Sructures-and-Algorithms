#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

void selectionSort(list &data, int left, int right)
{
    for (size_t i = left; i < right; i++)
    {
        int ind = i - 1;
        dataType current = data[i];

        int j;
        for (j = i - 1; j >= 0 && data[j] > current; --j)
        {
            data[j + 1] = data[j];
        }

        data[j + 1] = current;
    }
}