#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkSum(const size_t *developers, const size_t &targetSum, const size_t &length, const size_t &teams) {
    size_t teamsCount = 0;
    size_t currentSum = 0;

    size_t i = 0;
    while (i < length) {
        currentSum += developers[i];

        if (developers[i] > targetSum) {
            return false;
        }

        if (currentSum > targetSum) {
            teamsCount++;
            currentSum = 0;
            i--;
        }
        i++;
    }

    teamsCount++;

    return teamsCount <= teams;
}

size_t binarySearch(const size_t *developers,const size_t& upperBound, const size_t& length, const size_t& teams) {
    size_t left = 1;
    size_t right = upperBound;
    size_t currentMinMaxSum = 0;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        if (checkSum(developers, mid, length, teams)) {
            currentMinMaxSum = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return currentMinMaxSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t N, T;
    cin >> N >> T;

    size_t developers[N];
    for (size_t i = 0; i < N; ++i) {
        cin >> developers[i];
    }

    if (N > T) {
        size_t maxSum = 0;
        for (size_t i = 0; i < N; ++i) {
            maxSum += developers[i];
        }

        cout << binarySearch(developers, maxSum, N, T);
    } else if (N == T) {
        cout << *max_element(developers, developers + N);
    }

    return 0;
}
