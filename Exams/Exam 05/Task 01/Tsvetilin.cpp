#include <iostream>
#include <unordered_map>
#include <set>

std::unordered_map<std::string, size_t> m;

int main()
{

    std::string input;
    while (std::cin >> input)
    {
        m[input]++;
    }

    std::set<std::string> s;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second == 1)
            s.insert(iter->first);
    }

    for (auto &x : s)
    {
        std::cout << x << "\n";
    }

    return 0;
}
