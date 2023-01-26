#include <bits/stdc++.h>

using namespace std;

struct Interval {
    size_t time;
    long long value;

    bool operator<(const Interval &other) const {
        return this->time < other.time || (this->time == other.time && this->value > other.value);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N, Q, start, end, query;
    cin >> N >> Q;

    multiset <Interval, less<Interval>> intervals;

    for (size_t i = 0; i < N; i++) {
        cin >> start >> end;
        intervals.insert(Interval{start, 1});
        intervals.insert(Interval{end, -1});

    }

    vector <size_t> queries;

    for (size_t i = 0; i < Q; i++) {
        cin >> query;
        queries.push_back(query);
        intervals.insert(Interval{query, 0});
    }

    map<size_t, long long> intervalFrequency;
    long long counter = 0;

    for (const auto &interval: intervals) {
        counter += interval.value;
        if (interval.value == 0) {
            intervalFrequency[interval.time] = counter;
        }
    }

    for (const auto &query: queries) {
        cout << intervalFrequency[query] << " ";
    }

    return 0;
}