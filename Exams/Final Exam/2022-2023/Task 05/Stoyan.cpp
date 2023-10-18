#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

struct Pair {
    size_t id;
    size_t time;
};


using namespace std;

unordered_map<size_t, int> moneyMap;
unordered_map<int, size_t> counter;

int main() {
    size_t time, T, N, id;
    cin >> N;

    queue <Pair> p;
    set <size_t> times;
    size_t maxTime = 0;
    for (size_t i = 0; i < N; ++i) {
        cin >> id >> time;
        p.push({id, time});
        times.insert(time);
        maxTime = max(time, maxTime);
    }

    long long maxPair = 0;
    long long maxId = -1;
    while (!p.empty()) {
        size_t currentId = p.front().id;
        counter[currentId]++;
        if (counter[currentId] >= maxPair) {
            maxPair = counter[currentId];
            maxId = currentId;
        }
        moneyMap[p.front().time] = maxId;
        p.pop();
    }

    cin >> T;
    for (size_t i = 0; i < T; ++i) {
        cin >> time;
        if (time >= maxTime) {
            cout << moneyMap[maxTime] << '\n';
            continue;
        }
        auto tempTime = times.lower_bound(time);
        if (time < *tempTime) {
            if (tempTime == times.begin()) {
                cout << -1 << '\n';
                continue;
            }
            time = *(--tempTime);
        } else {
            time = *tempTime;
        }

        cout << moneyMap[time] << '\n';
    }
    return 0;
}