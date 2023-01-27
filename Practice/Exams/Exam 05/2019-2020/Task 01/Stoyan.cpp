#include <bits/stdc++.h>

using namespace std;

unordered_map <string, size_t> townMap;

int main() {
    size_t N, M, dist;
    cin >> N >> M;
    string town;
    for (size_t i = 0; i < N; i++) {
        cin >> town >> dist;
        townMap[town] = dist;
    }

    size_t sum = 0;
    for (size_t i = 0; i < M; i++) {
        cin >> town;
        sum += townMap[town];
    }

    cout << sum;
    return 0;
}
