#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t numbersCount, magicNumber;
    std::cin >> numbersCount >> magicNumber;
    // key - number, value - indexes where it was found
    std::unordered_map<size_t, size_t> left, right;
    std::vector<size_t> numbers;

    for (size_t i = 0; i < numbersCount; i++) {
        size_t current;
        std::cin >> current;
        right[current]++;
        numbers.push_back(current);
    }

    size_t counter = 0;

    for (size_t i = 0; i < numbers.size(); i++) {
        right[numbers[i]]--; // corner case with equal numbers with magic number one
        if (numbers[i] % magicNumber == 0) {
            counter += (left[numbers[i] / magicNumber]) * (right[numbers[i] * magicNumber]);
        }

        left[numbers[i]]++;
    }

    std::cout << counter;

    return 0;
}