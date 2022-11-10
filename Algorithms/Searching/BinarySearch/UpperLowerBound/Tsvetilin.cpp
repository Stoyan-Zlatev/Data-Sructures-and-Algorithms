#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

int lower_bound(int lowerBound, int upperBound, dataType &target, list &data)
{
    int mid;

    while (lowerBound < upperBound)
    {
        mid = lowerBound + (upperBound - lowerBound) / 2;

        if (data[mid] < target)
            lowerBound = mid + 1;
        else
            upperBound = mid;
    }
    
    return upperBound;
}

int upper_bound(int lowerBound, int upperBound, dataType &target, list &data)
{
    int mid;

    while (lowerBound < upperBound)
    {
        mid = lowerBound + (upperBound - lowerBound) / 2;

        if (data[mid] <= target)
            lowerBound = mid + 1;
        else
            upperBound = mid;
    }

    return upperBound;
}