#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, unordered_map<size_t, bool>> townMap;

int main() {
    size_t M, Q, connections, town, startTown;
    cin >> M;

    for (size_t i = 0; i < M; i++) {
        cin >> connections;
        for (size_t j = 0; j < connections; j++) {
            cin >> town;
            townMap[i][town] = true;
            townMap[town][i] = true;
        }
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        cin >> connections;
        cin >> startTown;
        bool hasPath = true;
        if (townMap.find(startTown) == townMap.end()) {
            hasPath = false;
        }
        for (size_t j = 1; j < connections; j++) {
            cin >> town;
            if (hasPath && !townMap[startTown][town]) {
                hasPath = false;
            }

            startTown = town;
        }

        cout << hasPath << " ";
    }

    return 0;
}
