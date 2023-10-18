#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

size_t competitorsCount(size_t *competitors, size_t size, size_t minWeight, size_t maxWeight) {
    size_t *upper = upper_bound(competitors, competitors + size, maxWeight);
    size_t *lower = lower_bound(competitors, competitors + size, minWeight);
    return size_t(upper - lower);
}

int main() {
    size_t N, Q;
    cin >> N >> Q;

    size_t weights[N];
    size_t minWeight, maxWeight;
    for (size_t i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    sort(weights, weights + N);

    for (size_t i = 0; i < Q; ++i) {
        cin >> minWeight >> maxWeight;
        if (minWeight > maxWeight) {
            cout << 0 << "\n";
        } else {
            cout << competitorsCount(weights, N, minWeight, maxWeight) << "\n";
        }
    }
    return 0;
}
