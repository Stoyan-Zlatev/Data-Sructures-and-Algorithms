#include <bits/stdc++.h>

using namespace std;

struct Time {
    size_t startTime, waitTime;

    Time(size_t startTime, size_t waitTime) {
        this->startTime = startTime;
        this->waitTime = waitTime;
    }

    bool operator>(const Time &other) const {
        return this->waitTime > other.waitTime;
    }
};

int main() {
    size_t N, min = 1e7, max = 0;
    cin >> N;
    size_t numbers[N];
    for (size_t i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    priority_queue<Time, vector<Time>, greater<Time>> tasks;
    tasks.push(Time(0, numbers[0]));
    size_t startTime = 0;

    for (size_t i = 0; i < N; i++) {
        size_t neededTime = startTime - tasks.top().startTime + tasks.top().waitTime;
        if (neededTime < min)
            min = neededTime;
        if (neededTime > max)
            max = neededTime;

        size_t finishTime = tasks.top().waitTime + startTime;
        tasks.pop();
        for (size_t j = startTime + 1; j <= finishTime && j < N; j++) {
            tasks.push(Time(j, numbers[j]));
        }

        startTime = finishTime;
    }
    
    cout << min << " " << max;
}
