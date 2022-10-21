#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

bool binary(list &data, size_t left, size_t right, dataType target)
{
    size_t mid;

    while (left <= right)
    {

        mid = left + (right - left) / 2;

        if (data[left] == target)
            return true;

        if (data[left] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}