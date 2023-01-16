#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N, c2 = 0, c3 = 0, c5 = 0;
    cin >> N;
    vector<size_t> dp(N + 1);
    dp[0] = 1;
    for (size_t i = 0; i <= N; ++i) {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == 2 * dp[c2]) {
            c2++;
        } else if (dp[i] == 3 * dp[c3]) {
            c3++;
        } else if (dp[i] == 5 * dp[c5]) {
            c5++;
        }
    }

    cout << dp[N-1];
}
