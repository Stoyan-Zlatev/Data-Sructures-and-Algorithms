#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_POSITION = 1e6;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x;
    cin >> x;

    vector<int> indexes;
    int position;
    bool positions[MAX_POSITION];
    int max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> position;
        if (positions[position] == 0) {
            positions[position] = 1;
            if (max < position) {
                max = position;
            }
        }
    }

    // We make it to distinct the array of indexes
    for (int i = 0; i <= max; ++i) {
        if (positions[i]) {
            indexes.push_back(i);
        }
    }

    int destroyed = 0;
    int fallen = 0;
    while (indexes.size() > (fallen + destroyed)) {
        destroyed++;
        for (int i = fallen; i < indexes.size() - destroyed; i++) {
            indexes[i] -= x;
            if (indexes[i] < 1) {
                fallen++;
            }
        }
    }

    cout << destroyed;
    return 0;
}
