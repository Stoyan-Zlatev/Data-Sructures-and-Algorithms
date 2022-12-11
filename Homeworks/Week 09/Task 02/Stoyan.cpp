#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, number;
    cin >> N;
    unordered_map<size_t, size_t> numberIndex;
    vector<size_t> numbers;
    size_t maxSequenceCount = 0, start = 0;
    for (size_t currentIndex = 0; currentIndex < N; currentIndex++) {
        cin >> number;
        numbers.push_back(number);
        if (!numberIndex.count(number)) {
            numberIndex.insert(pair<size_t, size_t>(number, currentIndex));
            if ((currentIndex - start + 1) > maxSequenceCount) {
                maxSequenceCount = (currentIndex - start + 1);
            }
        } else {
            for (size_t k = start; k < numberIndex[number]; ++k) {
                numberIndex.erase(numbers[k]);
            }
            start = numberIndex[number] + 1;
            numberIndex[number] = currentIndex;
        }
    }

    cout << maxSequenceCount;

    return 0;
}
