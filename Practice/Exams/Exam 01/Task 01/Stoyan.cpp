#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Team {
    size_t id;
    double xi, yi;
    
    double getPoints() const {
        return xi * xi/ yi;
    }

    bool operator<(const Team& other) const {
        return this->getPoints() > other.getPoints() ||
                (this->getPoints() == other.getPoints() && this->xi > other.xi);
    }
};

int main() {
    long long N;
    cin >> N;

    Team teams[N];
    for (int i = 0; i < N; ++i) {
        teams[i].id = i + 1;
        cin >> teams[i].xi >> teams[i].yi;
    }

    sort(teams, teams + N);

    for (int i = 0; i < N; ++i) {
        cout << teams[i].id << " ";
    }
    return 0;
}
