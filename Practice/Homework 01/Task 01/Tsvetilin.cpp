#include <bits/stdc++.h>
#include <climits>

int main()
{
    std::string input;
    char search;

    std::cin >> input;
    std::cin >> search;

    std::vector<int> searchedIndexes;

    int length = input.length();
    
    for (int i = 0; i < length; ++i)
    {
        if (input[i] == search)
        {
            searchedIndexes.push_back(i);
        }
    }
    searchedIndexes.push_back(INT_MAX);

    int currentNearestIndex = 0;
    for (int i = 0; i < length; ++i)
    {
        int leftClose = std::abs(i - searchedIndexes[currentNearestIndex]);
        int rightClose = std::abs(i - searchedIndexes[currentNearestIndex + 1]);
        int distance = std::min(leftClose, rightClose);
        std::cout << distance << " ";

        if (rightClose == 0)
        {
            ++currentNearestIndex;
        }
    }
}
