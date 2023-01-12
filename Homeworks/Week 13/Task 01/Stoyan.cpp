#include <iostream>

using namespace std;

const size_t TARGET = 10080;
const size_t MAX_SIZE = 1000;
const size_t MOD = 1000000007;
size_t matrix[MAX_SIZE + 1][TARGET + 1];

void init(const size_t &N, size_t *arr) {
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (size_t i = 0; i <= N; i++) {
        matrix[i][0] = 1;
    }
    for (size_t i = 1; i <= TARGET; i++) {
        matrix[0][i] = 0;
    }
}

size_t findAllSums(const size_t &N) {
    size_t count = 0;
    for (size_t i = 0; i <= TARGET; i++) {
        count += matrix[N][i];
        count %= MOD;
    }

    return count;
}

void solve(const size_t &N, const size_t *numbers) {
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= TARGET; j++) {
            matrix[i][j] = matrix[i - 1][j];
            if (numbers[i - 1] <= j) {
                matrix[i][j] += (matrix[i - 1][j - numbers[i - 1]]) % MOD;
            }
        }
    }
}

int main() {
    size_t N;
    cin >> N;

    size_t numbers[N];

    init(N, numbers);
    solve(N, numbers);

    cout << findAllSums(N);
    return 0;
}
