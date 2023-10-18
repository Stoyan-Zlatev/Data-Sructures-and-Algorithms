#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> remainders;

int main() {
    size_t N;
    cin >> N;

    vector<int> targets(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> targets[i];
    }

    sort(targets.begin(), targets.end());
    for (size_t i = 0; i < N; ++i) {
        if (remainders[targets[i]]) {
            cout << "true";
            return 0;
        }
        for (size_t j = i + 1; j < N; ++j) {
            remainders[abs(targets[j] - targets[i])] = true;
        }
    }

    cout << "false";
    return 0;
}
