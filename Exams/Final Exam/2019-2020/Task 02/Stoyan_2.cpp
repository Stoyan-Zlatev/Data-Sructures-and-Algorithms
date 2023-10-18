#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N, Q;
    int number;
    cin >> N;
    vector<int> numbers(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> number;
        auto lower = lower_bound(numbers.begin(), numbers.end(), number);
        if (*lower != number) {
            cout << (lower - numbers.begin()) << '\n';
        } else {
            cout << (lower - numbers.begin()) << " ";
            cout << (upper_bound(numbers.begin(), numbers.end(), number) - numbers.begin() - 1) << '\n';
        }
    }
    return 0;
}
