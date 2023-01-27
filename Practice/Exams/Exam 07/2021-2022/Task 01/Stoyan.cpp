#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, size_t> peopleMap;
unordered_map<size_t, bool> added;

int main() {
    size_t N;
    cin >> N;
    size_t arr[N];
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
        peopleMap[arr[i]]++;
    }

    queue <size_t> order;
    vector <size_t> result;
    for (size_t i = 0; i < N; ++i) {
        if (peopleMap[arr[i]] == 1) {
            result.push_back(arr[i]);
        } else if (added.find(arr[i]) == added.end()) {
            added[arr[i]] = true;
            order.push(i);
        }
    }

    while (!order.empty()) {
        result.push_back(arr[order.front()]);
        order.pop();
    }

    for (const auto &element: result) {
        cout << element << " ";
    }
    return 0;
}
