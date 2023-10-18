#include <iostream>
#include <algorithm>
#include <climits>

const size_t MAX_SIZE = 1e3;

bool diags[MAX_SIZE + 5][MAX_SIZE + 5];
long long matrix[MAX_SIZE + 5][MAX_SIZE + 5];
long long dp[MAX_SIZE + 5][MAX_SIZE + 5];

long long solve(size_t x, size_t y)
{
    if (x == 0 && y == 0)
    {
        return matrix[x][y];
    }

    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }

    if (x == 0)
    {
        return dp[x][y] = solve(x, y - 1) + matrix[x][y];
    }

    if (y == 0)
    {
        return dp[x][y] = solve(x - 1, y) + matrix[x][y];
    }

    dp[x][y] = std::max(std::max(solve(x - 1, y), solve(x, y - 1)), (diags[x][y]) ? solve(x - 1, y - 1) : LLONG_MIN) + matrix[x][y];

    return dp[x][y];
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
            dp[i][j] = 0;
            diags[i][j] = false;
        }
    }

    size_t k;
    std::cin >> k;

    long long x, y;
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> x >> y;
        diags[x][y] = true;
    }

    dp[0][0] = 0;
    std::cout << solve(n - 1, n - 1);

    return 0;
}
