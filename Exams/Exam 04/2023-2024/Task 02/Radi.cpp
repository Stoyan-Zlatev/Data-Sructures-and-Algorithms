#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(1);
    size_t N;
    cin >> N;
    double tmp;
    priority_queue<double, vector<double>, less<double>> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

    size_t currentSize = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> tmp;
        currentSize++;
        if (!minHeap.empty() && tmp > minHeap.top())
        {
            minHeap.push(tmp);
        }
        else
        {
            maxHeap.push(tmp);
        }
        if (minHeap.size() == maxHeap.size() + 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() == minHeap.size() + 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (currentSize % 2 == 0)
        {
            cout << (minHeap.top() + maxHeap.top()) / 2 << endl;
            continue;
        }
        if (currentSize % 2 == 1 && maxHeap.size() > minHeap.size())
        {
            cout << maxHeap.top() << endl;
            continue;
        }
        if (currentSize % 2 == 1 && minHeap.size() > maxHeap.size())
        {
            cout << minHeap.top() << endl;
        }
    }
    return 0;
}
