https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/problem
#include <bits/stdc++.h>

using namespace std;

const size_t MAX_SIZE = 2e3 + 2;
size_t weights[MAX_SIZE], values[MAX_SIZE];
unordered_map<size_t, unordered_map<size_t, size_t>> valueMap;

size_t solve(size_t N, size_t sum) {
    if (valueMap[N][sum] != 0) {
        return valueMap[N][sum];
    }

    if (N == 0) {
        return 0;
    }

    if (sum < weights[N - 1]) {
        return valueMap[N][sum] = solve(N - 1, sum);
    }

    return valueMap[N][sum] = max(solve(N - 1, sum), solve(N - 1, sum - weights[N - 1]) + values[N - 1]);
}

int main() {
    size_t T, N, target;
    cin >> T;
    for (size_t i = 0; i < T; ++i) {
        cin >> target >> N;
        for (size_t j = 0; j < N; ++j) {
            cin >> weights[j];
            cin >> values[j];
        }

        cout << solve(N, target) << endl;
        valueMap.clear();
    }
}
