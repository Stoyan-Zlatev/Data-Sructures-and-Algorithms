//Find all the ways to reach the bottom right corner, starting from the top left and you can only go down or right
#include <bits/stdc++.h>

using namespace std;

size_t N, M;
unordered_map<size_t, unordered_map<size_t, size_t>> hashMap;

bool isInBoundaries(const size_t &x, const size_t &y) {
    return x < N && x >= 0 && y < M && y >= 0;
}

size_t traverse(size_t x = N - 1, size_t y = M - 1) {
    if (!isInBoundaries(x, y)) {
        return 0;
    }

    if (hashMap.find(x) != hashMap.end() && hashMap[x].find(y) != hashMap[x].end()) {
        return hashMap[x][y];
    }

    hashMap[x][y] = traverse(x - 1, y) + traverse(x, y - 1);
    return hashMap[x][y];
}


int main() {
    cin >> N >> M;

    hashMap[0][0] = 1;
    traverse();
    cout << hashMap[N - 1][M - 1];
}
