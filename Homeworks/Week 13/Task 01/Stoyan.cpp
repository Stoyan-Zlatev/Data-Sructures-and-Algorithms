#include <iostream>

using namespace std;

const size_t TARGET = 10080;
const size_t MAX_SIZE = 1000;
const size_t MOD = 1e9 + 7;
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

size_t findAllSums(const size_t &N, const size_t *numbers) {
    for (size_t i = 1; i < N; i++) {
        for (size_t j = 1; j <= TARGET; j++) {
            matrix[i][j] = matrix[i - 1][j];
            if (numbers[i - 1] <= j) {
                matrix[i][j] += (matrix[i - 1][j - numbers[i - 1]]) % MOD;
            }
        }
    }
    
    // because of the empty subset, since the inner loop start from 1
    size_t count = 1;
    for (size_t j = 1; j <= TARGET; j++) {
        matrix[N][j] = matrix[N - 1][j];
        if (numbers[N - 1] <= j) {
            matrix[N][j] += (matrix[N - 1][j - numbers[N - 1]]) % MOD;
        }
        count += matrix[N][j];
        count %= MOD;
    }

    return count;
}

int main() {
    size_t N;
    cin >> N;

    size_t numbers[N];

    init(N, numbers);
    cout << findAllSums(N, numbers);
    
    return 0;
}
