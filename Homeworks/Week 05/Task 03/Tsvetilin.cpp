#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

std::stack<long long> positive;
std::queue<long long> negative;
bool passed = false;

void battle()
{
    while (negative.size() > 0 && positive.size() > 0)
    {
        if (abs(negative.front()) == positive.top())
        {
            positive.pop();
            negative.pop();
        }
        else if (abs(negative.front()) > positive.top())
        {
            positive.pop();
        }
        else if (abs(negative.front()) < positive.top())
        {
            negative.pop();
        }
    }
}

void passNegative()
{
    while (negative.size() > 0)
    {
        std::cout << negative.front() << " ";
        negative.pop();
        passed = true;
    }
}

void passPositive()
{
    std::stack<long long> rev;
    while (positive.size() > 0)
    {
        rev.push(positive.top());
        positive.pop();
        passed = true;
    }

    while (rev.size() > 0)
    {
        std::cout << rev.top() << " ";
        rev.pop();
    }
}

int main()
{

    int n;
    std::cin >> n;

    int i = 0;
    long long x = 0;

    bool isPositive = false;

    while (i < n)
    {
        ++i;
        std::cin >> x;

        if (!isPositive && x > 0)
        {
            battle();
            passNegative();
        }

        isPositive = x > 0;
        if (isPositive)
            positive.push(x);
        else
            negative.push(x);
    }

    battle();
    passNegative();
    passPositive();

    if (!passed)
    {
        std::cout << '\n';
    }

    return 0;
}