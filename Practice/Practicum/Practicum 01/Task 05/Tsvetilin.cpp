#include <iostream>

int countLast(int remain)
{
    if (remain <= 0)
        return 0;

    int count = 0;

    if (remain >= 1 && remain <= 20)
        ++count;

    if (remain % 2 == 0 && remain / 2 <= 20)
        ++count;

    if (remain % 3 == 0 && remain / 3 <= 20)
        ++count;

    if (remain == 25)
        ++count;

    if (remain == 50)
        ++count;

    return count;
}

int main()
{

    int required;
    std::cin >> required;

    int count = 0;

    for (size_t i = 1; i <= 20; i++)
    {
        int remain = required - 2 * i;

        if (remain <= 0)
        {
            count += (count == 0) * 3;
            break;
        }

        count += 3 * countLast(remain);

        for (size_t j = 1; j <= 20 && j <= remain; j++)
        {
            count += countLast(remain - j);
            count += countLast(remain - 2 * j);
            count += countLast(remain - 3 * j);
        }

        count += countLast(remain - 25);
        count += countLast(remain - 50);
    }

    if (required - 50 == 0)
    {
        count += 3;
    }
    else
    {
        count += 3 * countLast(required - 50);

        for (size_t j = 1; j <= 20; j++)
        {
            count += countLast(required - 50 - j);
            count += countLast(required - 50 - 2 * j);
            count += countLast(required - 50 - 3 * j);
        }

        count += countLast(required - 75);
        count += countLast(required - 100);
    }

    std::cout << count;
}