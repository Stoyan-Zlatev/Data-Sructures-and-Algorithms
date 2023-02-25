#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>

const size_t MAX_SIZE = 3e3;
size_t ans[MAX_SIZE + 5]{};
std::unordered_map<char, size_t> letters;

int main()
{
    std::string input;
    std::cin >> input;

    for (size_t i = 0; i <= input.size(); i++)
    {
        ans[i] = INT_MAX;
    }

    ans[0] = 0;

    for (size_t i = 0; i < input.size() - 1; ++i)
    {
        if (ans[i] == INT_MAX)
            continue;

        letters.clear();

        for (size_t j = i; j < input.size(); ++j)
        {
            letters[(size_t)input[j]]++;
            bool isPossible = true;

            for (auto iter = letters.begin(); iter != letters.end(); iter++)
            {
                if (iter->second % 2 == 0 && iter->second > 0)
                {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible)
                ans[j + 1] = std::min(ans[i] + 1, ans[j + 1]);
        }
    }

    std::cout << ans[input.size()];
}
