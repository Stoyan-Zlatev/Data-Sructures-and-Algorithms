#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

int main() {
    queue<long> elements;
    deque<long> second;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long current;
        std::cin >> current;
        elements.push(current);
    }

    while (!elements.empty()) {
        long currentFirst = elements.front();
        if (currentFirst < 0 && second.empty()) {
            std::cout << currentFirst << " ";
            elements.pop();
        }
        else if (currentFirst < 0 && !second.empty()) {
            long currentSecond = second.back();
            currentFirst = abs(currentFirst);
            if (currentFirst > currentSecond) {
                second.pop_back();
            }
            else if(currentFirst < currentSecond) {
                elements.pop();
            }
            else {
                elements.pop();
                second.pop_back();
            }
        }
        else {
            second.push_back(currentFirst);
            elements.pop();
        }
    }

    while (!second.empty()) {
        std::cout << second.front() << " ";
        second.pop_front();
    }

    return 0;
}