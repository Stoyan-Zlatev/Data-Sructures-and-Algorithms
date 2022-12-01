#include <bits/stdc++.h>

using namespace std;

struct Time {
    size_t startTime;
    size_t neededTime;
    size_t index;
    
    Time(size_t startTime, size_t neededTime, size_t index) {
        this->startTime = startTime;
        this->neededTime = neededTime;
        this->index = index;
    }

    bool operator>(const Time &other) const {
        return this->startTime > other.startTime;
    }

    bool operator<(const Time &other) const {
        return this->neededTime > other.neededTime ||
               (this->neededTime == other.neededTime && this->index > other.index);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, t, f;
    cin >> N;

    priority_queue<Time, vector<Time>, greater<Time>> banici;
    priority_queue<Time, vector<Time>, less<Time>> redBanici;

    for (size_t i = 0; i < N; ++i) {
        cin >> t >> f;
        banici.push(Time(t, f, i));
    }

    size_t startTime;
    for (size_t i = 0; i < N; ++i) {
        if (redBanici.empty()) {
            startTime = banici.top().startTime;
            redBanici.push(banici.top());
            banici.pop();
        }
        
        cout << redBanici.top().index << " ";
        startTime += redBanici.top().neededTime;
        redBanici.pop();

        while (!banici.empty() && banici.top().startTime <= startTime) {
            redBanici.push(banici.top());
            banici.pop();
        }
    }
    
    return 0;
}
