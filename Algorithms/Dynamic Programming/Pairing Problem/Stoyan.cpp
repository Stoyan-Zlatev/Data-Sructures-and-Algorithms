#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N;
    cin >> N;
    vector<size_t> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    cout << dp[N];
}
