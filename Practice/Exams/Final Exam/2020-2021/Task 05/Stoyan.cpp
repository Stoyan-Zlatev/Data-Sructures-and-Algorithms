#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, T, B, N, number;
    cin >> B >> T >> K >> N;
    multiset <size_t> numbers;
    for (size_t i = 1; i <= N; ++i) {
        cin >> number;
        numbers.insert(number);
        if (i % T == 0 && K) {
            K--;
            if (numbers.size() >= B) {
                for (size_t j = 0; j < B; ++j) {
                    cout << *numbers.begin() << " ";
                    numbers.erase(numbers.begin());
                }
            }
        }
    }

    while (K--) {
        if (numbers.size() >= B) {
            for (size_t j = 0; j < B; ++j) {
                cout << *numbers.begin() << " ";
                numbers.erase(numbers.begin());
            }
        }
    }
    return 0;
}
