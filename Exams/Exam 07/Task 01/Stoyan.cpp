#include <bits/stdc++.h>

using namespace std;

const size_t MAX_SIZE = 2e3 + 5;
long long dp[MAX_SIZE][MAX_SIZE];
bool diagonals[MAX_SIZE][MAX_SIZE];

long long solve(const size_t &x, const size_t &y, const vector<vector<long long>> &arr) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    if (x == 0) {
        return dp[x][y] = solve(x, y - 1, arr) + arr[x][y];
    }
    if (y == 0) {
        return dp[x][y] = solve(x - 1, y, arr) + arr[x][y];
    }

    dp[x][y] = max(max(solve(x - 1, y, arr), solve(x, y - 1, arr)),
                   diagonals[x][y] ? solve(x - 1, y - 1, arr) : LLONG_MIN) +
               arr[x][y];
    return dp[x][y];
}

int main() {
    size_t N, K, x, y;
    cin >> N;
    vector<vector<long long>> arr(N, vector<long long>(N));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    cin >> K;
    for (size_t i = 0; i < K; ++i) {
        cin >> x >> y;
        diagonals[x][y] = true;
    }

    dp[0][0] = arr[0][0];
    cout << solve(N - 1, N - 1, arr);
}