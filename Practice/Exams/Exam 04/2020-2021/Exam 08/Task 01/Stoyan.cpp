#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, bool> sums;

int main() {
    size_t N, number;
    cin >> N;

    vector <size_t> numbers(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    for (size_t i = 0; i < N - 1; ++i) {
        if (sums[numbers[i]]) {
            cout << "true";
            return 0;
        }
        for (size_t j = i + 1; j < N; ++j) {
            sums[numbers[j] - numbers[i]] = true;
        }
    }

    cout << (sums[numbers[N - 1]] ? "true" : "false");
    return 0;
}
