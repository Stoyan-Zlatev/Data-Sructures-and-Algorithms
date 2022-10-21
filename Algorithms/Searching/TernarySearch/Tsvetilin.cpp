#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

bool ternary(list &data, size_t left, size_t right, dataType target)
{
    size_t mid1 = left + (right - left) / 3;
    size_t mid2 = right - (right - left) / 3;

    if (data[mid1] == target || data[mid2] == target)
        return true;

    if (target < data[mid1])
        return ternary(data, left, mid1 - 1, target);
    else if (target < data[mid2])
        return ternary(data, mid1 + 1, mid2 - 1, target);
    else
        return ternary(data, mid2 + 1, right, target);
}