#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    size_t Q, wordsCount1, wordsCount2;
    string s;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> wordsCount1 >> wordsCount2;
        map<string, long long> sent1;

        for (size_t j = 0; j < wordsCount1; j++)
        {
            cin >> s;
            sent1[s]++;
        }
        bool found = true;
        for (size_t j = 0; j < wordsCount2; j++)
        {
            cin >> s;
            if (sent1[s] == 0)
            {
                found = false;
            }
            sent1[s]--;
        }
        cout << (found ? "Yes\n" : "No/n");
    }
    return 0;
}