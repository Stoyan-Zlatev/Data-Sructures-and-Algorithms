#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    int howMany;
    char ch;
    cin >> str >> howMany >> ch;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    count *= howMany / str.length();

    for (size_t i = 0; i < howMany % str.length(); i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    cout<<count;
}