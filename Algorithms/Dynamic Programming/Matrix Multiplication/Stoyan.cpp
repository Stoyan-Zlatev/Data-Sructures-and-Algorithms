#include <bits/stdc++.h>

using namespace std;

const size_t MAX_SIZE = 2e3+2;
size_t matrixMap[MAX_SIZE][MAX_SIZE];

size_t solve(const size_t *matrixes, size_t i, size_t j) {
    if (j - i == 1) {
        return matrixMap[i][j] = matrixes[i - 1] * matrixes[i] * matrixes[j];
    }

    if (j == i) {
        return 0;
    }

    if (matrixMap[i][j] != INT_MAX) {
        return matrixMap[i][j];
    }

    for (size_t k = i; k < j; ++k) {
        size_t tempValue =
                solve(matrixes, i, k) + solve(matrixes, k + 1, j) + matrixes[i - 1] * matrixes[k] * matrixes[j];
        matrixMap[i][j] = min(matrixMap[i][j], tempValue);
    }

    return matrixMap[i][j];
}

int main() {
    size_t N;
    cin >> N;

    size_t matrixes[N];
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            matrixMap[i][j] = INT_MAX;
        }
    }
    for (size_t i = 0; i < N; ++i) {
        cin >> matrixes[i];
    }

    cout << solve(matrixes, 1, N - 1);
}
