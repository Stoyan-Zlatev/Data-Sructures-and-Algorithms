#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    size_t N, S;
    cin >> N >> S;

    priority_queue<size_t, vector<size_t>, greater<size_t>> pq;

    size_t temp;
    for (size_t i = 0; i < N; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    
    size_t days = 0;
    while (pq.top() < S && pq.size() > 1)
    {
        size_t n = pq.top();
        pq.pop();
        if (pq.size() == 0)
        {
            cout << -1;
            return 0;
        }

        n += 2 * pq.top();
        pq.pop();

        pq.push(n);
        days++;
    }

    cout << (pq.top() >= S ? (long long)days : (long long)-1);

    return 0;
}