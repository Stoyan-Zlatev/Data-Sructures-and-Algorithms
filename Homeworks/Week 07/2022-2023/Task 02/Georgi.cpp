#include <vector>
#include <iostream>
#include <map>

int* readArray(size_t length) {
    int* arr = new int[length];
    for (size_t i = 0; i < length; i++) {
        std::cin >> arr[i];
    }

    return arr;
}

void printMaxUniqueSubArrayLength(int* arr, size_t length) {
    std::map<int, size_t> container; // key - number, value - index of the last time you saw it
    size_t max = 0;
    size_t currentStartIndex = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (container.find(arr[i]) != container.end()) {
            if (i - currentStartIndex > max) {
                max = i - currentStartIndex;
            }

            if (container[arr[i]] >= currentStartIndex) {
                currentStartIndex = container[arr[i]] + 1;
            }
        }

        container[arr[i]] = i;
    }

    if (currentStartIndex < length && length - currentStartIndex > max) {
        max = length - currentStartIndex;
    }

    std::cout << max << '\n';
}

int main() {
    size_t queries;
    std::cin >> queries;

    for (size_t i = 0; i < queries; i++) {
        size_t n;
        std::cin >> n;
        int* arr = readArray(n);
        printMaxUniqueSubArrayLength(arr, n);
        delete[] arr;
    }

    return 0;
}