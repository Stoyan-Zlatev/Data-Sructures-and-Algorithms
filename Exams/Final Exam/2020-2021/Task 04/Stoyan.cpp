#include <bits/stdc++.h>

using namespace std;

unordered_map<int, size_t> numbersMap;

int main() {
    size_t N, maxSize = 0, size = 0, number, startIndex = 0;
    cin >> N;

    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        if (numbersMap.find(number) == numbersMap.end() || numbersMap[number] < startIndex) {
            numbersMap[number] = i;
        } else {
            size = i - startIndex;
            if (maxSize < size) {
                maxSize = size;
            }
            startIndex = numbersMap[number] + 1;
            numbersMap[number] = i;
        }
    }

    size = N - startIndex;
    if (maxSize < size) {
        maxSize = size;
    }

    cout << maxSize;
    return 0;
}
