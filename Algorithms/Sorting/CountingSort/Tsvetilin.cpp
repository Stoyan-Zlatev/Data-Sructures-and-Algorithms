#include <vector>
#include <iostream>

// dataType should have implicit conversion to int
typedef int dataType;
typedef std::vector<dataType> list;

void countingSort(list &data, int length)
{
    list copy(length);

    dataType max = data[0];
    for (int i = 0; i < length; ++i)
    {
        copy[i] = data[i];
        if (max < data[i])
            max = data[i];
    }

    int *count = new int[max + 1];
    for (size_t i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < length; ++i)
    {
        ++count[data[i]];
    }

    for (int i = 1; i <= max; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--)
    {
        data[count[copy[i]] - 1] = copy[i];
        count[copy[i]] = count[copy[i]] - 1;
    }
}