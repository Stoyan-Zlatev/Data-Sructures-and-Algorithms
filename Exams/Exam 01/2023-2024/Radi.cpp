#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX_SYMBOLS = 63;
const size_t MAX_INDEXES = 2e7;

size_t counters[MAX_SYMBOLS]{0};
size_t indexes[MAX_INDEXES]{0};

size_t decode(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 10;
    }
    else
    {
        return ch - 'a' + 37;
    }
}

int main()
{

    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); i++)
    {
        counters[decode(s[i])]++;
    }

    size_t j = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (counters[decode(s[i])] == 1)
        {
            indexes[j++] = i;
        }
    }

    sort(indexes, indexes + j);

    for (size_t i = 0; i < j; i++)
    {
        cout << indexes[i] << " ";
    }

    return 0;
}