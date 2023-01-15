#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> solve(const size_t& N, const vector<long long>& arr) {
    long long subArraySum = arr[0], subSetSum = 0, currentSum = 0;

    for (size_t i = 0; i < N; ++i) {
        if (arr[i] >= 0) {
            subSetSum += arr[i];
        }
        currentSum += arr[i];
        currentSum = max(currentSum, arr[i]);
        subArraySum = max(subArraySum, currentSum);
    }

    auto maxElement = std::max_element(arr.begin(), arr.end());
    if (*maxElement < 0) {
        return {subArraySum, *maxElement};
    }

    return {subArraySum, subSetSum};
}

int main() {
    size_t T, N;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        cin >> N;
        vector<long long> arr(N);
        for (size_t j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        auto sums = solve(N, arr);
        cout << sums.first << " " << sums.second << endl;
    }

}
