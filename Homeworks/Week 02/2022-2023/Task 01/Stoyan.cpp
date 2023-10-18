#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int odds = N - 1;
    int evens = 0;

    int numbers[N];
    int currentNumber;
    for (int i = 0; i < N; i++) {
        cin >> currentNumber;
        if (currentNumber % 2 == 0) {
            numbers[evens++] = currentNumber;
        } else {
            numbers[odds--] = currentNumber;
        }
    }

    for (int i = 0; i < evens; i++) {
        cout << numbers[i] << '\n';
    }

    for (int i = N - 1; i > odds; i--) {
        cout << numbers[i] << '\n';
    }

    return 0;
}
