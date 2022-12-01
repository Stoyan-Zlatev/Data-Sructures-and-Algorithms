#include <bits/stdc++.h>

using namespace std;

priority_queue<size_t, vector<size_t>, less<size_t>> minPriorityQueue;
priority_queue<size_t, vector<size_t>, greater<size_t>> maxPriorityQueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    size_t N, number;
    cin >> N;

    long double median = 0;

    for (size_t i = 1; i <= N; i++) {
        cin >> number;

        if (number >= median) {
            maxPriorityQueue.push(number);
            if (maxPriorityQueue.size() > (minPriorityQueue.size() + 1)) {
                minPriorityQueue.push(maxPriorityQueue.top());
                maxPriorityQueue.pop();
            }
        } else {
            minPriorityQueue.push(number);
            if (minPriorityQueue.size() > (maxPriorityQueue.size() + 1)) {
                maxPriorityQueue.push(minPriorityQueue.top());
                minPriorityQueue.pop();
            }
        }
        if (i % 2 == 0) {
            median = (maxPriorityQueue.top() + minPriorityQueue.top()) / 2.0;
            cout << median << fixed << setprecision(1) << '\n';
        } else {
            median = ((maxPriorityQueue.size() > minPriorityQueue.size()) ? maxPriorityQueue.top()
                                                                          : minPriorityQueue.top()) * 1.0;
            cout << median << fixed << setprecision(1) << '\n';
        }
    }
    return 0;
}
