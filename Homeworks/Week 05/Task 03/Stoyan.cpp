#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


int main() {
    size_t N;
    cin >> N;
    long long iq;
    deque<long long> fromBurevo;
    deque<long long> toBurevo;
    bool passed = false;
    for (size_t i = 0; i < N; i++) {
        cin >> iq;
        if (iq > 0) {
            if (fromBurevo.empty()) {
                while (!toBurevo.empty()) {
                    cout << toBurevo.front() << " ";
                    toBurevo.pop_front();
                    passed = true;
                }
            }
            fromBurevo.push_back(iq);
        } else {
            toBurevo.push_back(iq);
            while (!toBurevo.empty() && !fromBurevo.empty()) {
                if (abs(toBurevo.front()) == fromBurevo.back()) {
                    fromBurevo.pop_back();
                    toBurevo.pop_front();
                } else if (abs(toBurevo.front()) > fromBurevo.back()) {
                    fromBurevo.pop_back();
                } else if (abs(toBurevo.front()) < fromBurevo.back()) {
                    toBurevo.pop_front();
                }
            }
        }
    }
    while (!toBurevo.empty()) {
        cout << toBurevo.front() << " ";
        toBurevo.pop_front();
        passed = true;
    }

    while (!fromBurevo.empty()) {
        cout << fromBurevo.front() << " ";
        fromBurevo.pop_front();
        passed = true;
    }

    if (!passed) {
        cout << "\n";
    }

    return 0;
}
