#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Coordinates {
    size_t x;
    size_t y;

    Coordinates(size_t x, size_t y) : x(x), y(y) {}
};

bool isInBoundaries(size_t x, size_t y, size_t N, size_t M) {
    return x <= N && x > 0 && y > 0 && y <= M;
}

int main() {
    size_t N, M, T;
    cin >> N >> M >> T;
    bool isRotten[N + 1][M + 1] = {};
    queue<Coordinates> apples;
    size_t x, y;
    size_t totalCount = 0;
    while (cin >> x >> y) {
        if (isInBoundaries(x, y, N, M)) {
            apples.push(Coordinates(x, y));
            isRotten[x][y] = true;
            totalCount++;
        }
    }

    for (size_t i = 0; i < T; i++) {
        size_t applesToCheck = apples.size();
        for (size_t j = 0; j < applesToCheck; j++) {
            size_t currentX = apples.front().x, currentY = apples.front().y;
            apples.pop();
            
            //Check right
            if (isInBoundaries(currentX + 1, currentY, N, M) && !isRotten[currentX + 1][currentY]) {
                apples.push(Coordinates(currentX + 1, currentY));
                isRotten[currentX + 1][currentY] = true;
                totalCount++;
            }
            //Check down
            if (isInBoundaries(currentX, currentY + 1, N, M) && !isRotten[currentX][currentY + 1]) {
                apples.push(Coordinates(currentX, currentY + 1));
                isRotten[currentX][currentY + 1] = true;
                totalCount++;
            }
            //Check left
            if (isInBoundaries(currentX - 1, currentY, N, M) && !isRotten[currentX - 1][currentY]) {
                apples.push(Coordinates(currentX - 1, currentY));
                isRotten[currentX - 1][currentY] = true;
                totalCount++;
            }
            //Check up
            if (isInBoundaries(currentX, currentY - 1, N, M) && !isRotten[currentX][currentY - 1]) {
                apples.push(Coordinates(currentX, currentY - 1));
                isRotten[currentX][currentY - 1] = true;
                totalCount++;
            }
        }
    }

    cout << M * N - totalCount;
    return 0;
}
