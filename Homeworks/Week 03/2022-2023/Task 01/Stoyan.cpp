#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

unsigned long long ternarySearch(unsigned long long start, unsigned long long end, unsigned long long searched,
              unsigned long long iteration) {
    if (start >= end) {
        return iteration;
    }

    unsigned long long mid1 = start + (end - start) / 3;
    unsigned long long mid2 = end - (end - start) / 3;

    if (mid1 >= searched) {
        return ternarySearch( start, mid1, searched, iteration + 1);
    } else if (mid2 <= searched) {
        return ternarySearch(mid2, end, searched, iteration + 1);
    }

    return iteration;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    unsigned long long N, P;
    std::cin >> P >> N;

    unsigned long long totalFriends = pow(3, P);
    unsigned long long friendNumbers[N];
    for (unsigned long long i = 0; i < N; i++) {
        std::cin >> friendNumbers[i];
    }

    for (unsigned long long i = 0; i < N; ++i) {
        std::cout << ternarySearch(1, totalFriends, friendNumbers[i], 1) << "\n";
    }
    return 0;
}
