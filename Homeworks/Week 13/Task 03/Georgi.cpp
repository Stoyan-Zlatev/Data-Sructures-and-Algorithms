#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

const int COUNTER_SIZE = 26;
const int MAX_SPLITS = 3000;
int dp[3001] = {};

bool hasEven(const int* arr) {
    for (size_t i = 0; i < COUNTER_SIZE; i++) {
        if (arr[i] != 0 && !(arr[i] & 1)) {
            return true;
        }
    }

    return false;
}

void initDP(size_t size) {
    dp[0] = 0;
    dp[1] = 1;

    for (size_t i = 2; i <= size; i++) {
        dp[i] = MAX_SPLITS;
    }
}

void printDP(size_t size) {
    for (size_t i = 0; i <= size; i++) {
        std::cout << dp[i] << " ";
    }

    std::cout << '\n';
}

void populateDP(std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (dp[i] == MAX_SPLITS) {
            continue;
        }

        int counter[COUNTER_SIZE] = {};

        for (size_t j = i; j < str.size(); j++) {
            counter[str[j] - 'a']++;

            if (!hasEven(counter)) {
                dp[j + 1] = std::min(dp[i] + 1, dp[j + 1]);
            }
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::cin >> input;

    initDP(input.size());
    populateDP(input);
    std::cout << dp[input.size()];

    return 0;
}