https://www.hackerrank.com/challenges/equal/problem
#include <bits/stdc++.h>

using namespace std;

size_t solve(vector<size_t>& options) {
    size_t operations = 0;
    vector<size_t> count(5, 0);
    size_t min_value = *min_element(options.begin(), options.end());
    for (auto &x: options) {
        x -= min_value;
        operations += x / 5;
        x = x % 5;
        count[x]++;
    }

    size_t normal_ops =
            count[1] + count[2] + 2 * count[3] + 2 * count[4];
    size_t add1_ops =
            count[0] + count[1] + 2 * count[2] + 2 * count[3] + count[4];
    size_t add2_ops =
            count[0] + 2 * count[1] + 2 * count[2] + count[3] + 2 * count[4];
    
    operations += min(normal_ops, min(add1_ops, add2_ops));
    return operations;
}

int main() {
    size_t T, N;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        cin >> N;
        vector<size_t> options(N);
        for (size_t j = 0; j < N; ++j) {
            cin >> options[j];
        }
        cout << solve(options) << endl;
    }
}
