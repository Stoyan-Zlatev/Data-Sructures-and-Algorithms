#include <iostream>
#include <queue>

int main()
{

    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> tasks;

    size_t kGroupSize, time, bGroupsCount, n;

    std::cin >> kGroupSize >> time >> bGroupsCount >> n;

    size_t x;
    for (size_t i = 1; i <= n && bGroupsCount > 0; i++)
    {
        std::cin >> x;
        tasks.push(x);

        if (i % time)
            continue;

        for (size_t j = 0; j < kGroupSize; j++)
        {
            std::cout << tasks.top() << " ";
            tasks.pop();
        }
        
        --bGroupsCount;
    }

    bGroupsCount *= kGroupSize;
    while (bGroupsCount > 0)
    {
        std::cout << tasks.top() << " ";
        tasks.pop();
        --bGroupsCount;
    }

    return 0;
}
