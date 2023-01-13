//Find all the ways to reach the bottom right corner, starting from the top left and you can only go down or right
#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, bool> memo;
stack<size_t> resultSubset;

bool solve(const vector<size_t>& numbers, long long sum, const size_t& number = 0) {
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
        if (solve(numbers, sum - element, element)) {
            resultSubset.push(element);
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

    cout << "{ ";
    if (solve(numbers, targetSum)) {
        while (!resultSubset.empty()) {
            cout << resultSubset.top() << " ";
            resultSubset.pop();
        }
    }
    cout << "}";
}
