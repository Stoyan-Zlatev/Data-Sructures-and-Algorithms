#include <iostream>
#include <algorithm>

const size_t MAX_SIZE = 5e6;
const size_t MOD = 1e9 + 7;

size_t dp[MAX_SIZE + 500]{};

size_t perms(long long n)
{
    if (dp[n] != 0)
        return dp[n];

    if (n <= 0)
        return 0;

    if (n == 1)
        return 2;

    dp[n] = ((n >= 0 && dp[n - 2] ? dp[n - 2] : perms(n - 2)) + (n >= 0 && dp[n - 1] ? dp[n - 1] : perms(n - 1))) % MOD;

    return dp[n];
}

int main()
{
    size_t n;
    std::cin >> n;

    dp[0] = 0;
    dp[1] = 2;

    for (size_t i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    std::cout << dp[n];

    return 0;
}