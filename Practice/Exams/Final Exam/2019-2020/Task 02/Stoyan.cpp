#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> numbersMap;
unordered_map<int, pair<int, int>> numberPosition;
unordered_map<int, int> orderedNumberPosition;

int main() {
    size_t N, Q, query;
    cin >> N;
    vector<int> numbers(N);
    multiset<int> copyNumbers;
    for (size_t i = 0; i < N; ++i) {
        cin >> numbers[i];
        copyNumbers.insert(numbers[i]);
        if (!numbersMap[numbers[i]]) {
            numberPosition[numbers[i]] = {i, i};
        } else {
            numberPosition[numbers[i]].second = i;
        }
        numbersMap[numbers[i]] = true;
    }
    cin >> Q;
    size_t index = 0;
    for (const auto &element: copyNumbers) {
        if (orderedNumberPosition.find(element) == orderedNumberPosition.end()) {
            orderedNumberPosition[element] = index;
        }
        index++;
    }
    for (size_t i = 0; i < Q; ++i) {
        cin >> query;
        if (numbersMap[query]) {
            cout << numberPosition[query].first << " " << numberPosition[query].second << '\n';
        } else {
            size_t result = *copyNumbers.upper_bound(query);
            if (orderedNumberPosition.find(result) != orderedNumberPosition.end()) {
                cout << orderedNumberPosition[result] << '\n';
            } else {
                cout << N << '\n';
            }
        }
    }
    return 0;
}
