#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const long long MOD = 1e9 + 7;
const int MAX = 10080;
size_t dpContainer[MAX + 1] = { 0 };

struct Pair {
    size_t index, toAdd;
};

void populateDPContainer(std::vector<size_t>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
        size_t current = numbers[i];
        
        if(current > MAX) {
            break;
        }

        std::vector<Pair> toIncrement;
        for (size_t j = 0; j < MAX + 1; j++) {
            if (dpContainer[j] == 0) {
                continue;
            }

            if (current + j > MAX) {
                break;
            }
            
            toIncrement.push_back({ current + j, dpContainer[j] });
        }

        dpContainer[current]++;
        for (size_t j = 0; j < toIncrement.size(); j++) {
            dpContainer[toIncrement[j].index] += (toIncrement[j].toAdd % MOD);
        }
    }
}

int main() {
    size_t count;
    std::cin >> count;
    std::vector<size_t> numbers;

    for (size_t i = 0; i < count; i++) {
        size_t current;
        std::cin >> current;
        if (current <= MAX) {
            numbers.push_back(current);
        }
    }

    populateDPContainer(numbers);

    size_t result = 1;
    for (size_t i = 0; i < MAX + 1; i++) {
        result += dpContainer[i];
        result %= MOD;
    }

    std::cout << result;

    return 0;
}