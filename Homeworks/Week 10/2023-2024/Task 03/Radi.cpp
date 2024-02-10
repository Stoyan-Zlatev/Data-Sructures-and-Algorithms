#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

vector<char> graph['z' + 1];
bool letters['z' + 1]{false};
stack<char> sorted;

bool visited['z' + 1];

void dfs(char letter)
{
    if (visited[letter])
    {
        return;
    }

    visited[letter] = true;

    for (auto &neighbour : graph[letter])
    {
        dfs(neighbour);
    }

    sorted.push(letter);
}

int main()
{
    size_t N;
    cin >> N;

    vector<string> words(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        size_t len = min(words[i].length(), words[i + 1].length());

        for (size_t j = 0; j < len; j++)
        {
            if (words[i][j] == words[i + 1][j])
                continue;

            graph[words[i][j]].push_back(words[i + 1][j]);
            letters[words[i][j]] = true;
            letters[words[i + 1][j]] = true;

            break;
        }
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        if (!letters[i])
            continue;
        dfs(i);
    }

    while (!sorted.empty())
    {
        cout << sorted.top() << " ";
        sorted.pop();
    }

    return 0;
}