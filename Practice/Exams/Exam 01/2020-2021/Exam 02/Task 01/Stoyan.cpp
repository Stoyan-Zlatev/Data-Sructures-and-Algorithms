#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, size_t> numberMap;
const size_t MAX_NUMBER = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t N;
    cin >> N;

    size_t number;
    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        numberMap[number]++;
    }

    for (int i = MAX_NUMBER; i >= 0; --i) {
        if (numberMap[i]) {
            for (size_t j = 0; j < numberMap[i]; ++j) {
                cout << i << " ";
            }
        }
    }
    
    return 0;
}
