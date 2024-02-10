#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    size_t result = 0;
    size_t currentMax = 0;

    for (size_t i = 0; i < s1.size(); i++)
    {
        currentMax = 0;
        size_t iCopy = i;
        size_t j = 0;
        while (iCopy < s1.size() && j < s2.size())
        {
            if (s1[iCopy] != s2[j])
            {
                currentMax = 0;
            }
            else
            {
                currentMax++;
                result = max(result, currentMax);
            }

            iCopy++;
            j++;
        }
    }

    cout << result;

    return 0;
}