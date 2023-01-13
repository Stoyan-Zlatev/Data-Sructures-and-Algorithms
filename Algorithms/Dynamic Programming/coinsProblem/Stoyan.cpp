//Here we are returning the least amout of coins (from the options available) needed to pay targetSum
#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, long long> moneyMap;
vector<size_t> options;

long long solve(long long sum) {
    if (sum < 0) {
        return INT_MAX;
    }
    if (moneyMap[sum] != INT_MAX) {
        return moneyMap[sum];
    }
    if (sum == 0) {
        return 0;
    }


    for (const auto &option: options) {
        moneyMap[sum] = min(moneyMap[sum], solve(sum - option) + 1);
    }

    return moneyMap[sum];
}

int main() {
    size_t targetSum;
    cin >> targetSum;
    options = {2, 3, 7};
    moneyMap[0] = 0;
    for (size_t i = 1; i <= targetSum; ++i) {
        moneyMap[i] = INT_MAX;
    }

    cout << solve(targetSum);
}
