#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, size_t> numbersMap;

int main() {
    size_t N, Q, query, number;
    cin >> N;

    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        numbersMap[number] = i;
    }

    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> query;
        if (numbersMap.find(query) != numbersMap.end()) {
            cout << numbersMap[query] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
