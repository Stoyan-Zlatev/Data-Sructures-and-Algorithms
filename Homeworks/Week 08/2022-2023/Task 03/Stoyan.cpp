#include <bits/stdc++.h>

using namespace std;

priority_queue<size_t, vector<size_t>, greater<size_t>> numbers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t K, T, B, N, number;
    cin >> K >> T >> B >> N;

    for (size_t i = 1; i <= N && B > 0; i++) {
        cin >> number;
        numbers.push(number);
        if (i % T == 0) {
            for (size_t j = 0; j < K; j++) {
                cout << numbers.top() << " ";
                numbers.pop();
            }
            B--;
        }
    }

    for (size_t i = 0; i < B; i++){
        for (size_t j = 0; j < K; j++) {
            cout << numbers.top() << " ";
            numbers.pop();
        }
    }

    return 0;
}
