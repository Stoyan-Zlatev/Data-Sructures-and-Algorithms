#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct GymRat {
    size_t id;
    double di;
    double ti;

    double getWeightForTime() const {
        return di * di / ti;
    }

    bool operator<(const GymRat &other) const {
        return this->getWeightForTime() > other.getWeightForTime() ||
               (this->getWeightForTime() == other.getWeightForTime() && this->di > other.di);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t N;
    cin >> N;
    GymRat gymRats[N];
    for (int i = 0; i < N; ++i) {
        gymRats[i].id = i + 1;
        cin >> gymRats[i].di >> gymRats[i].ti;
    }

    sort(gymRats, gymRats + N);

    for (int i = 0; i < N; ++i) {
        cout << gymRats[i].id << " ";
    }
    return 0;
}
