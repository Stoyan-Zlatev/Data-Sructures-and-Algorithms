#include <bits/stdc++.h>

using namespace std;

const size_t MAX_SIZE = 2e3 + 5;
size_t dp[MAX_SIZE][MAX_SIZE];

int solve(const size_t &x, const size_t &y, const vector<vector<size_t>> &arr) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    if (x == 0) {
        return dp[x][y] = solve(x, y - 1, arr) + arr[x][y];
    }
    if (y == 0) {
        return dp[x][y] = solve(x - 1, y, arr) + arr[x][y];
    }


    dp[x][y] = min(solve(x - 1, y, arr), solve(x, y - 1, arr)) + arr[x][y];
    return dp[x][y];
}

int main() {
    size_t N;
    cin >> N;
    vector<vector<size_t>> arr(N, vector<size_t>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];

    cout << solve(N - 1, N - 1, arr);
}
