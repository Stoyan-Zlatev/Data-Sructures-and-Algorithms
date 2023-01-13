//Algorithm to check if we can get subset from the original array, where (subset sum) == targetSum
#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, bool> memo;

bool solve(const vector<size_t>& numbers, long long sum) {
    if (memo.find(sum) != memo.end()) {
        return memo[sum];
    }

    if (sum == 0) {
        return true;
    }

    if (sum < 0) {
        return false;
    }

    for (const auto& element: numbers) {
        if (solve(numbers, sum - element)) {
            memo[sum] = true;
            return true;
        }
    }

    memo[sum] = false;
    return false;
}

int main() {
    size_t N;
    long long targetSum;
    cin >> N >> targetSum;

    vector<size_t> numbers(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    cout << solve(numbers, targetSum);
}
