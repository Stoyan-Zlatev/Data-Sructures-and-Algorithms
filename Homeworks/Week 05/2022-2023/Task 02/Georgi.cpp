#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>

using namespace std;

int main() {
    queue<long long> elements;
    int n, groupCount;
    std::cin >> n >> groupCount;
    for (int i = 0; i < n; i++) {
        long long current;
        std::cin >> current;
        elements.push(current);
    }

    deque<long long> min;
    list<long long> currentNumbers;
    while (groupCount > 0 && !elements.empty()) {
        long long current = elements.front();
        currentNumbers.push_back(current);
        elements.pop();

        while (!min.empty() && current < min.back()) {
            min.pop_back();
        }

        min.push_back(current);
        groupCount--;
    }

    long long sum = min.front();

    while (!elements.empty()) {
        long long next = elements.front();
        long long toRemove = currentNumbers.front();
        currentNumbers.pop_front();
        if (toRemove == min.front()) {
            min.pop_front();
        }
        currentNumbers.push_back(next);

        while (!min.empty() && next < min.back()) {
            min.pop_back();
        }

        min.push_back(next);
        sum += min.front();
        elements.pop();
    }

    std::cout << sum;

    return 0;
}