#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

bool jump(list &data, size_t left, size_t right, dataType target)
{
    size_t jumpLength = sqrt(right - left);

    size_t previous = 0;
    size_t currentJump = 0;
    while (data[std::min(left + currentJump, right) - 1] < target)
    {
        if (left + currentJump >= right)
        {
            return false;
        }

        previous = currentJump;
        currentJump += jumpLength;
    }

    while (previous < std::min(currentJump, right))
    {
        if (data[previous] == target)
            return true;

        ++previous;
    }

    return false;
}