#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const size_t MAX = 2e7 + 2;
size_t input[MAX];

size_t decode(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0' + 1;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 11;
    }
    else
    {
        return ch - 'A' + 37;
    }
}

char encode(size_t n)
{
    if (n <= 10)
    {
        return n - 1 + '0';
    }
    else if (n <= 36)
    {
        return n - 11 + 'a';
    }
    else
    {
        return n - 37 + 'A';
    }
}

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        char curr;
        cin >> curr;
        input[decode(curr)]++;
    }
    for (size_t i = 1; i < 63; i++)
    {
        for (size_t j = 0; j < input[i]; j++)
        {
            cout << (char)encode(i);
        }
    }
    return 0;
}
