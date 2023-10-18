#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isSingle(size_t point) {
    return point <= 20 || point == 25;
}

bool isDouble(size_t point) {
    return point % 2 == 0 && point <= 40 || point == 50;
}

bool isTriple(size_t point) {
    return point % 3 == 0;
}

// A point could possibly be represented in 3 ways
// Example: 6 points = 1*6p./2*3p./3*2p.
size_t pointsRepresentationCount(size_t point) {
    size_t counter = 0;
    if (isSingle(point)) {
        counter++;
    }
    if (point != 0) {
        if (isDouble(point)) {
            counter++;
        }
        if (isTriple(point)) {
            counter++;
        }
    }

    return counter;
}

int main() {
    int N;
    cin >> N;

    // All possible points
    vector<int> arr;
    // Only points in the sector with double points + 50p.(2*25p.)
    vector<int> sector2;

    arr.push_back(0);
    for (int i = 1; i <= 20; i++) {
        arr.push_back(i);
        sector2.push_back(i * 2);
    }

    for (int i = 22; i <= 40; i += 2) {
        arr.push_back(i);
    }

    for (int i = 21; i <= 40; i += 6) {
        arr.push_back(i);
    }

    for (int i = 42; i <= 60; i += 3) {
        arr.push_back(i);
    }

    arr.push_back(25);
    sector2.push_back(50);
    arr.push_back(50);

    size_t counter = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (isDouble(arr[i])) {
            if (arr[i] == N) {
                counter++;
            }
        }
        for (int j = 0; j < arr.size(); ++j) {
            if (isDouble(arr[j]) && arr[j] != 0) {
                if (arr[i] + arr[j] == N) {
                    if (isSingle(arr[i])) {
                        counter++;
                    }
                    if (arr[i] != 0) {
                        if (isDouble(arr[i])) {
                            counter++;
                        }
                        if (isTriple(arr[i])) {
                            counter++;
                        }
                    }
                }
            }
            for (int k = 0; k < sector2.size(); k++) {
                if (arr[i] + arr[j] + sector2[k] == N) {
                    if (isSingle(arr[i])) {
                        counter += pointsRepresentationCount(arr[j]);
                    }
                    if (arr[i] != 0) {
                        if (isDouble(arr[i])) {
                            counter += pointsRepresentationCount(arr[j]);
                        }
                        if (isTriple(arr[i])) {
                            counter += pointsRepresentationCount(arr[j]);
                        }
                    }
                }
            }
        }
    }

    cout << counter;
    return 0;
}
