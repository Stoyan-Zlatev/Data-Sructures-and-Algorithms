#include <bits/stdc++.h>

using namespace std;

struct Interval {
    size_t time;
    int value;

    bool operator<(const Interval &other) const {
        return this->time < other.time || (this->time == other.time && this->value > other.value);
    }
};

int main() {
    size_t N, Q, from, to, query;
    cin >> N >> Q;

    multiset <Interval, less<Interval>> intervals;
    for (size_t i = 0; i < N; ++i) {
        cin >> from >> to;
        intervals.insert({from, 1});
        intervals.insert({to, -1});
    }


    queue <size_t> queries;
    for (size_t i = 0; i < Q; ++i) {
        cin >> query;
        queries.push(query);
        intervals.insert({query, 0});
    }

    unordered_map <size_t, size_t> intervalCounter;
    size_t counter = 0;
    for (const auto &interval: intervals) {
        counter += interval.value;
        if (interval.value == 0) {
            intervalCounter[interval.time] = counter;
        }
    }

    while (!queries.empty()) {
        cout << intervalCounter[queries.front()] << " ";
        queries.pop();
    }

    return 0;
}
