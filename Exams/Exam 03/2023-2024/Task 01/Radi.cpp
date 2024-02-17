#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        size_t K;
        cin >> K;
        long long number;
        bool isSymetrical = true;
        bool onlyNegs = true;
        bool onlyPoss = true;
        stack<long long> st;
        for (size_t j = 0; j < K; j++)
        {
            cin >> number;
            if (number >= 0)
            {
                onlyNegs = false;
                st.push(number);
                continue;
            }
            if (number < 0)
            {
                onlyPoss = false;
                if (!st.empty())
                {
                    if (st.top() != -number)
                    {
                        isSymetrical = false;
                    }
                    st.pop();
                }
            }
        }
        cout << (st.empty() && isSymetrical && !onlyPoss && !onlyNegs ? "YES\n" : "NO\n");
    }

    return 0;
}
