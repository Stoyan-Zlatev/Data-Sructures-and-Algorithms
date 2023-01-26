#include <bits/stdc++.h>

using namespace std;

priority_queue <size_t, vector<size_t>, less<size_t>> orders;

int main() {
    size_t N;
    cin >> N;
    long long order;

    for (size_t i = 0; i < N; i++) {
        cin >> order;
        if (order == -1) {
            if (!orders.empty()) {
                cout << orders.top() << " ";
                orders.pop();
            }
            continue;
        }

        orders.push(order);
    }
}