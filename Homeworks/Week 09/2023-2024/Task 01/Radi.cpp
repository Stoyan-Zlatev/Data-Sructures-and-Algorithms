#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    size_t count = 0;
    size_t s1_len = s1.size();
    size_t s_len = s2.size() - s1_len;
    for (size_t i = 0; i <= s_len; ++i)
    {
        if (s2[i] != s1[0])
        {
            continue;
        }

        bool success = true;
        for (size_t j = 0; j < s1_len; j++)
        {
            if (s2[i + j] != s1[0 + j])
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}
