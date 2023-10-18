#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, k, a, q;

    std::cin >> n >> k >> a >> q;

    std::set<size_t> hits;
    std::set<size_t>::iterator prev = hits.end(), next = hits.end(), curr;

    size_t freeSpaces = 1 + (n - a) / (a + 1);
    size_t x;

    for (size_t i = 0; i < q; ++i)
    {
        std::cin >> x;
        curr = (hits.insert(x)).first;

        if (hits.size() > 1)
        {
            prev = std::prev(curr);
            next = std::next(curr);
        }

        size_t nextValue = (next == hits.end() ? n + 1 : *next);
        size_t prevValue = (prev == hits.end() ? 0 : *prev);

        freeSpaces -= (nextValue - prevValue - 1 >= a) ? 1 + (nextValue - prevValue - 1 - a) / (a + 1) : 0;
        freeSpaces += (nextValue - x - 1 >= a) ? 1 + (nextValue - x - 1 - a) / (a + 1) : 0;
        freeSpaces += (x - prevValue - 1 >= a) ? 1 + (x - prevValue - 1 - a) / (a + 1) : 0;

        if (freeSpaces < k)
        {
            std::cout << i + 1;
            return 0;
        }
    }

    std::cout << -1;

    return 0;
}