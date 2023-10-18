#include <vector>
#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> q;

    size_t n, m;
    std::cin >> n >> m;

    size_t x;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;
        q.push(x);
    }

    size_t time = 0;

    while (q.size() > 1 && q.top() < m)
    {
        size_t add = q.top();
        q.pop();
        add += 2 * q.top();
        q.pop();
        q.push(add);
        time++;
    }

    if (q.top() < m)
        std::cout << -1;
    else
        std::cout << time;

    return 0;
}