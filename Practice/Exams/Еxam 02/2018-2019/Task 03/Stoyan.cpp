#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, bool> numbersMap;
const size_t MAX_NUMBER = 50000;

int main() {
    size_t N, number;
    cin >> N;

    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        numbersMap[number] = true;
    }

    for (size_t i = 0; i < MAX_NUMBER; ++i) {
        if (numbersMap[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
