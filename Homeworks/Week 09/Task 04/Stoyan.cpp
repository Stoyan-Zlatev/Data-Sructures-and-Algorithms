#include <bits/stdc++.h>

using namespace std;

size_t N, M, Msq;
unordered_map<size_t, size_t> numberFrequency;
unordered_map<size_t, unordered_map<size_t, size_t>> targetMultiplication;

const size_t findSpecialNumbersCount(const size_t *numbers) {
    size_t counter = 0;
    for (long long i = N; i >= 0; --i) {
        size_t firstNumber = numbers[i];
        size_t secondNumber = firstNumber * M;
        size_t targetNumber = firstNumber * Msq;
        if (targetMultiplication[secondNumber][targetNumber] > 0) {
            counter += targetMultiplication[secondNumber][targetNumber];
        }

        if (numberFrequency[secondNumber] > 0) {
            targetMultiplication[firstNumber][secondNumber] += numberFrequency[secondNumber];
        }

        numberFrequency[numbers[i]]++;
    }

    return
            counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    size_t numbers[N];
    Msq = M * M;

    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    cout << findSpecialNumbersCount(numbers);
    return 0;
}
