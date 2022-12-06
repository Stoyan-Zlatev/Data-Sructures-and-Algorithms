#include <bits/stdc++.h>

using namespace std;

struct Interval {
    size_t time;
    int value;

    Interval(size_t time, int value) {
        this->time = time;
        this->value = value;
    }

    bool operator<(const Interval &other) const {
        return this->time < other.time || (this->time == other.time && this->value > other.value);
    }
};


int main() {
    size_t N, start, end;
    size_t counter = 0;
    cin >> N;

    multiset<Interval, less<Interval>> intervals;

    while (N--) {
        cin >> start >> end;
        if (start != end) {
            intervals.insert({start, 1});
            intervals.insert({end - 1, -1});
        }
    }

    size_t max = 0;

    for (auto interval: intervals) {
        counter += interval.value;
        if (counter > max)
            max = counter;
    }

    cout << max;
    return 0;
}
