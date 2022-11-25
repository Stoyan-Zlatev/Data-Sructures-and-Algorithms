#include <bits/stdc++.h>

using namespace std;

size_t A, currentPosition;

void getFreeSpacesLeft(size_t &nextPosition, size_t &prevPosition, size_t &shipFreeSpaces) {
    if (nextPosition - prevPosition - 1 >= A) {
        shipFreeSpaces -= 1 + (nextPosition - prevPosition - 1 - A) / (A + 1);
    }
    if (nextPosition - currentPosition - 1 >= A) {
        shipFreeSpaces += 1 + (nextPosition - currentPosition - 1 - A) / (A + 1);
    }
    if (currentPosition - prevPosition - 1 >= A) {
        shipFreeSpaces += 1 + (currentPosition - prevPosition - 1 - A) / (A + 1);
    }

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t N, Q, K;
    cin >> N >> K >> A >> Q;
    size_t shipFreeSpaces = 1 + (N - A) / (A + 1);

    long long result = -1;

    set<size_t> shotPositions;
    for (size_t i = 1; i <= Q; i++) {
        cin >> currentPosition;
        auto currentIterator = shotPositions.insert(currentPosition).first;
        size_t prevPosition = currentIterator != shotPositions.begin() ? *prev(currentIterator) : 0;
        size_t nextPosition = next(currentIterator) != shotPositions.end() ? *next(currentIterator) : N + 1;

        getFreeSpacesLeft(nextPosition, prevPosition, shipFreeSpaces);
        if (shipFreeSpaces < K) {
            result = i;
            break;
        }
    }

    cout << result;
    return 0;
}
