#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Event {
    long long bi, ei;

    void init(istream &) {
        long long ti;
        cin >> bi >> ti;
        ei = bi + ti;
    }

    bool operator<(const Event &other) const {
        return this->bi < other.bi || (this->bi == other.bi && this->ei < other.ei);
    }
};

int main() {
    long long N;
    cin >> N;

    Event events[N];
    for (long long i = 0; i < N; ++i) {
        events[i].init(cin);
    }

    sort(events, events + N);

    long long count = N > 0 ? 1 : 0;
    long long previous = 0;
    for (long long i = 1; i < N; ++i) {
        if (events[previous].bi == events[i].bi) {
            continue;
        }
        if (events[i].bi < events[previous].ei) {
            if (events[i].ei < events[previous].ei) {
                previous = i;
            }
        } else {
            previous = i;
            count++;
        }
    }

    cout << count;
    return 0;
}
