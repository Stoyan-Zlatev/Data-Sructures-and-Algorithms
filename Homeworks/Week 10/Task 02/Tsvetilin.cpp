#include <iostream>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>

std::unordered_map<char, std::set<char>> g;
std::stack<char> sorted;
bool visited[CHAR_MAX + 1];

void dfs(char root)
{

    if (visited[root])
    {
        return;
    }

    visited[root] = true;

    for (auto iter = g[root].begin(); iter != g[root].end(); iter++)
    {
        dfs(*iter);
    }

    sorted.push(root);
}

void topologicalSort()
{
    for (auto iter = g.begin(); iter != g.end(); iter++)
    {
        dfs(iter->first);
    }
}

int main()
{

    size_t n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> words[i];
        for (size_t j = 0; j < words[i].length(); j++)
        {
            g[words[i][j]] = std::set<char>();
        }
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        size_t len = std::min(words[i].length(), words[i + 1].length());

        size_t j;
        for (j = 0; j < len; j++)
        {
            if (words[i][j] != words[i + 1][j])
                break;
        }

        if (words[i][j] == words[i + 1][j] || j == len)
            continue;

        g[words[i][j]].insert(words[i + 1][j]);
    }

    topologicalSort();

    while (!sorted.empty())
    {
        std::cout << sorted.top() << " ";
        sorted.pop();
    }

    return 0;
}
