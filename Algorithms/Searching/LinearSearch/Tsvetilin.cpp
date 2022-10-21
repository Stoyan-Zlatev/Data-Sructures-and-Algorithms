#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

bool linear(list &data, size_t left, size_t right, dataType target)
{
    while (left <= right)
    {
        if (data[left++] == target)
            return true;
    }

    return false;
}