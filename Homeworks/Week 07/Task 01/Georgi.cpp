#include <vector>
#include <iostream>
#include <set>

std::vector<short> getBinaryArray(unsigned long long number) {
    std::vector<short> result;
    while (number != 0) {
        result.push_back(number & 1);
        number >>= 1;
    }

    return result;
}

unsigned long long getBinaryNumber(std::vector<short>& binaryArray) {
    unsigned long long result = 0;
    for (int i = binaryArray.size() - 1; i >= 0; i--) {
        result = result * 10 + binaryArray[i];
    }

    return result;
}

void addCombinations(std::set<unsigned long long>& container, std::vector<short>& mask, short indexToChange) {
    if (indexToChange == mask.size()) {
        return;
    }

    container.insert(getBinaryNumber(mask));

    if (mask[indexToChange] == 1) {
        mask[indexToChange] = 0;
        addCombinations(container, mask, indexToChange);
        mask[indexToChange] = 1;
    }

    addCombinations(container, mask, indexToChange + 1);
}

void addBinaryMasks(std::set<unsigned long long>& container, unsigned long long number) {
    std::vector<short> binary = getBinaryArray(number);

    addCombinations(container, binary, 0);
}

int main() {
    std::set<unsigned long long> container;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        unsigned long long a;
        std::cin >> a;

        addBinaryMasks(container, a);
    }

    std::cout << container.size();

    return 0;
}