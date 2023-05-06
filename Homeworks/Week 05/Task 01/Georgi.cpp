#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

int matrix[1000][1000] = { 0 };

bool isEmpty(int x, int y, int rows, int cols) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        return false;
    }

    return matrix[x][y] == 0;
}

int main() {
    int rows, cols, days;
    std::cin >> rows >> cols >> days;

    Point p1, p2;
    std::cin >> p1.x >> p1.y;
    p1.x--;
    p1.y--;
    matrix[p1.x][p1.y] = 1;

    queue<Point> spoiled;
    spoiled.push(p1);

    while (std::cin >> p2.x >> p2.y) {
        p2.x--;
        p2.y--;
        matrix[p2.x][p2.y] = 1;
        spoiled.push(p2);
        break;
    }

    while (days > 0) {
        size_t length = spoiled.size();

        while (length > 0) {
            Point current = spoiled.front();
            spoiled.pop();

            if (isEmpty(current.x - 1, current.y, rows, cols)) {
                spoiled.push({ current.x - 1, current.y });
                matrix[current.x - 1][current.y] = 1;
            }
            if (isEmpty(current.x, current.y + 1, rows, cols)) {
                spoiled.push({ current.x, current.y + 1 });
                matrix[current.x][current.y + 1] = 1;
            }
            if (isEmpty(current.x + 1, current.y, rows, cols)) {
                spoiled.push({ current.x + 1, current.y });
                matrix[current.x + 1][current.y] = 1;
            }
            if (isEmpty(current.x, current.y - 1, rows, cols)) {
                spoiled.push({ current.x, current.y - 1 });
                matrix[current.x][current.y - 1] = 1;
            }

            spoiled.push(current);
            length--;
        }

        days--;
    }

    std::cout << (rows * cols) - spoiled.size();

    return 0;
}