#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

stack<size_t> posNums;
queue<size_t> negNums;

void passNegative()
{
    while (!negNums.empty())
    {
        cout << (long long)negNums.front() * (-1) << " ";
        negNums.pop();
    }
}

void passPositive()
{
    stack<size_t> posRev;
    while (!posNums.empty())
    {
        posRev.push(posNums.top());
        posNums.pop();
    }
    while (!posRev.empty())
    {
        cout << posRev.top() << " ";
        posRev.pop();
    }
}

// either positives or negatives win one battle -> only one goup passes
void battle(bool doPositivePass)
{

    while (!posNums.empty() && !negNums.empty())
    {
        if (posNums.top() > negNums.front())
        {
            negNums.pop();
        }
        else if (posNums.top() < negNums.front())
        {
            posNums.pop();
        }
        else
        {
            negNums.pop();
            posNums.pop();
        }
    }

    passNegative();
    if (!doPositivePass)
    {
        return;
    }
    passPositive();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t N;
    cin >> N;

    long long input;
    bool isPosWithoutNegative = true;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        if (input < 0)
        {
            isPosWithoutNegative = false;
            negNums.push(input * (-1));
            continue;
        }
        if (input > 0)
        {
            if (isPosWithoutNegative)
            {
                posNums.push(input);
                continue;
            }
            battle(false);
            posNums.push(input);
            isPosWithoutNegative = true;
        }
    }
    battle(true);
    cout << '\n';
    return 0;
}