#include <iostream>
#include <unordered_set>
#include <algorithm>

std::string first, second;

int main()
{
    std::cin >> first >> second;

    size_t maxSeq = 0;
    size_t currentSeq = 0;
    for (size_t i = 0; i < first.size(); i++)
    {
        currentSeq = 0;
        size_t row = i;
        for (size_t j = 0; j < second.size() && row < first.size(); j++, row++)
        {
            if (first[row] != second[j])
            {
                currentSeq = 0;
            }
            else
            {
                currentSeq++;
                maxSeq = std::max(maxSeq, currentSeq);
            }
        }
    }

    std::cout << maxSeq;

    return 0;
}