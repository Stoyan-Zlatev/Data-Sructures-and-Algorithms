#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

int main()
{
    size_t q;
    std::cin >> q;

    for (size_t i = 0; i < q; ++i)
    {
        size_t n;
        std::cin >> n;

        size_t maxCount = 0;
        size_t backInd = 0;

        std::queue<size_t> conseq;
        std::set<size_t> candyBox;

        size_t x;
        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> x;

            while (candyBox.find(x) != candyBox.end())
            {
                candyBox.erase(conseq.front());
                conseq.pop();
                ++backInd;
            }

            maxCount = std::max(maxCount, j - backInd + 1);
            conseq.push(x);
            candyBox.insert(x);
        }

        std::cout << maxCount << std::endl;
    }

    return 0;
}
