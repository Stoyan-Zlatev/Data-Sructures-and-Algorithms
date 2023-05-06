#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Order {
    size_t startTime;
    size_t requiredTime;
    size_t index;

    Order(size_t startTime, size_t requiredTime, size_t index) {
        this->startTime = startTime;
        this->requiredTime = requiredTime;
        this->index = index;
    }
};

struct TimeCompare {
    bool operator() (const Order& lhs, const Order& rhs)
    {
        return lhs.startTime > rhs.startTime;
    }
};

struct RequiredTimeCompare {
    bool operator() (const Order& lhs, const Order& rhs)
    {
        if (lhs.requiredTime == rhs.requiredTime) {
            return lhs.index > rhs.index;
        }

        return lhs.requiredTime > rhs.requiredTime;
    }
};

int main() {
    priority_queue<Order, vector<Order>, RequiredTimeCompare> canBeStarted;
    priority_queue<Order, vector<Order>, TimeCompare> canNotBeStarted;

    size_t length;
    std::cin >> length;

    for (size_t i = 0; i < length; i++) {
        size_t startTime, requiredTime;
        std::cin >> startTime >> requiredTime;
        canNotBeStarted.push(Order(startTime, requiredTime, i));
    }

    size_t time = 1;
    while (!canBeStarted.empty() || !canNotBeStarted.empty()) {
        while (!canNotBeStarted.empty() && canNotBeStarted.top().startTime <= time) {
            Order top = canNotBeStarted.top();
            canNotBeStarted.pop();
            canBeStarted.push(top);
        }

        if (!canBeStarted.empty()) {
            // which order will be done
            Order toBeDone = canBeStarted.top();
            time += toBeDone.requiredTime;
            std::cout << toBeDone.index << " ";
            canBeStarted.pop();
        }
        else {
            time++;
        }
    }

    return 0;
}