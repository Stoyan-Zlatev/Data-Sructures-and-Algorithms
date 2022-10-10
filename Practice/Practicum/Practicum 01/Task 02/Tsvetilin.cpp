#include <iostream>
#include <climits>

const size_t MAX_COUNT = 1e6;

int marks[MAX_COUNT]{};

int main()
{

    int minMark;
    size_t n;

    std::cin>>minMark;
    std::cin>>n;

    unsigned long long overMark = 0;
    size_t countOvers = 0;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> marks[i];

        if (marks[i] > minMark)
        {
            overMark += (marks[i] - minMark);
            if (overMark > INT_MAX)
            {
                overMark %= INT_MAX;
                ++countOvers;
            }
            marks[i] = minMark;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (marks[i] < minMark)
        {
            int deficit = minMark - marks[i];
            if (overMark >= deficit || countOvers > 0)
            {
                if (deficit >= overMark)
                {
                    deficit -= overMark;
                    --countOvers;
                    overMark = INT_MAX - deficit;
                }
                else
                {
                    overMark -= deficit;
                }
            }
            else
            {
                std::cout << "no";
                return 0;
            }
        }
    }

    std::cout << "yes";
}