#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

bool check(list &data, dataType target)
{
    return true;
}

int binary(int lowerBound, int upperBound, list &data)
{
    int mid;

    while (lowerBound <= upperBound)
    {
        mid = lowerBound + (upperBound - lowerBound) / 2;
        if (check(data, mid))
            upperBound = mid - 1;
        else
            lowerBound = mid + 1;
    }

    return lowerBound;
}