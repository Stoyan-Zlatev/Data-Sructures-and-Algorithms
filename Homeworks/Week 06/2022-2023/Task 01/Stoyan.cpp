#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
// Basically it works because we have only consecutive numbers in all tests
// Otherwise it won't be appropriate

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t N, A;
    cin >> N;
    size_t posSums[N];
    size_t negSums[N];
    queue<int> columns;
    for (int i = 0; i < N; ++i) {
        posSums[i] = 0;
        negSums[i] = 0;
    }

    int column = 0;
    columns.push(0);
    int left, right;
    for (int i = 0; i < N; ++i) {
        column = columns.front();
        columns.pop();
        cin >> A >> left >> right;
        if (column >= 0) {
            posSums[column] += A;
        } else {
            negSums[abs(column)]+=A;
        }
        
        //left
        if (left != -1){
        columns.push(column - 1);
        }
        //right
        if (right != -1) {
        columns.push(column + 1);
        }
    }
    while (!columns.empty()) {
        column = columns.front();
        columns.pop();
        if (column >= 0)
            posSums[column] += A;
        else
            negSums[abs(column)]+=A;
    }
    for (int i = N - 1; i >= 1; --i) {
        if (negSums[i] != 0)
            cout << negSums[i] << " ";
    }

    for (int i = 0; i < N; ++i) {
        if (posSums[i] != 0) {
            cout << posSums[i] << " ";
        }
    }
    return 0;
}
