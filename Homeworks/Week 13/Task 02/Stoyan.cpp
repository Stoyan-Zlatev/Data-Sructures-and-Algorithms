#include <bits/stdc++.h>

using namespace std;

const size_t MOD = 1e9 + 7;

int main() {
    size_t N, current1 = 0, current2 = 2, result = 2;
    cin >> N;

    for (size_t i = 1; i < N; ++i) {
        result = (current1 + current2) % MOD;
        current1 = current2;
        current2 = result;
    }

    cout << result % MOD;
}
