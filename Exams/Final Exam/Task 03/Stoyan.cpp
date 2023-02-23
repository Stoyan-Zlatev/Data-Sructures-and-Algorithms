#include <bits/stdc++.h>

using namespace std;

struct Pair {
    size_t time;
    int value;
    size_t index;

    bool operator>(const Pair &other) const {
        return this->time > other.time || (this->time == other.time && this->value > other.value);
    }
};

unordered_map <size_t, size_t> chairMap;

struct Chair {
    size_t timeIn, timeOut;
};

int main() {
    priority_queue <size_t, std::vector<size_t>, std::greater<size_t>> freeChairs;
    size_t N, T;
    size_t in, out;
    cin >> N;

    for (size_t i = 0; i <= N; ++i) {
        freeChairs.push(i);
    }

    priority_queue <Pair, vector<Pair>, greater<Pair>> pq;
    vector <Chair> q;
    for (size_t i = 0; i < N; ++i) {
        cin >> in >> out;
        q.push_back({in, out});
        pq.push({in, 1, i});
        pq.push({out, -1, i});
    }

    cin >> T;
    int neededTime = q[T].timeIn;

    while (!pq.empty()) {
        if (pq.top().value == 1) {
            chairMap[pq.top().index] = freeChairs.top();
            if (pq.top().time == neededTime) {
                cout << freeChairs.top();
                break;
            }
            freeChairs.pop();
        } else if (pq.top().value == -1) {
            freeChairs.push(chairMap[pq.top().index]);
        }
        pq.pop();
    }

    return 0;
}