#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> ordersMap;

int main() {
    int N, number;
    cin >> N;

    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        ordersMap[number]++;
    }

    size_t orders = 0, counter = 0;;
    for (const auto &order: ordersMap) {
        if (order.second % 10) {
            counter++;
        }
        orders += order.second % 10;
    }

    cout << counter << " " << orders;
    return 0;
}