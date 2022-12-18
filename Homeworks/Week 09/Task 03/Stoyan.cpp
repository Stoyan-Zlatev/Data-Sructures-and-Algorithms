#include <bits/stdc++.h>

using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    size_t M = first.size(), N = second.size();

    size_t maxSequence = 0;
    for (size_t row = 0, currentRow = 0; row < M; ++row, ++currentRow) {
        size_t sequence = 0;
        for (size_t column = 0; column < N && currentRow < M; ++column) {
            if (first[currentRow++] != second[column]) {
                sequence = 0;
            } else {
                sequence++;
                maxSequence = max(maxSequence, sequence);
            }
        }
    }

    cout << maxSequence;
}
