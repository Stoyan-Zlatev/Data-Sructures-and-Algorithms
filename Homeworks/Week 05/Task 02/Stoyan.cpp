#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


long long findMinKSum(deque<long long> &laziness, size_t &k) {
    long long minElement = laziness[0];
    deque<long long> subDeq;
    for (size_t i = 0; i < k; i++) {
        subDeq.push_back(laziness[i]);
        if (minElement > laziness[i])
            minElement = laziness[i];
    }

    long long sum = minElement;
    long long lastMin;
    while (laziness.size() > k) {
        lastMin = laziness.front();

        laziness.pop_front();

        subDeq.pop_front();
        subDeq.push_back(laziness[k - 1]);
        if (subDeq.back() < minElement) {
            minElement = subDeq.back();
        } else if (minElement == lastMin) {
            minElement = subDeq.front();
            for (size_t i = 1; i < k; i++) {
                minElement = min(minElement, subDeq[i]);
            }
        }

        sum += minElement;
    }

    return sum;
}


int main() {
    size_t N, k;
    cin >> N >> k;

    long long lazy;
    deque<long long> laziness;
    for (size_t i = 0; i < N; i++) {
        cin >> lazy;
        laziness.push_back(lazy);
    }

    cout << findMinKSum(laziness, k);
    return 0;
}
