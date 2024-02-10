#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;
    set<size_t> s;
    size_t inOrder[100000];
    for (size_t i = 1; i <= N; i++)
        s.insert(i);

    for (size_t i = 0; i < M; i++)
    {
        size_t input;
        cin >> input;
        s.erase(input);
        inOrder[i] = input;
    }

    size_t index = 0;
    while (!s.empty())
    {
        while (index < M && inOrder[index] < *s.begin())
        {
            cout << inOrder[index] << " ";
            index++;
        }
        cout << *s.begin() << " ";
        s.erase(*s.begin());
    }
    while (index < M)
    {
        cout << inOrder[index] << " ";
        index++;
    }

    return 0;
}
