#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t countOccurences[26]{0};

int main()
{
    size_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        size_t n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        for (size_t j = 0; j < str.length(); j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
            {
                continue;
            }
            countOccurences[str[j] - 'A']++;
        }

        for (size_t h = 0; h < 26; h++)
        {
            if (countOccurences[h] >= k)
            {
                cout << char('A' + h);
            }
        }
        cout << '\n';
    }

    return 0;
}
