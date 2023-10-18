#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, unordered_map<size_t, vector < size_t>>>
townMap;
unordered_map<size_t, bool> numbers;

int main() {
    size_t N, M, K, T, L, from, to, weight, number;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        townMap[from][to].push_back(weight);
    }

    cin >> K;
    for (size_t i = 0; i < K; ++i) {
        cin >> number;
        numbers[number] = true;
    }

    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        cin >> L;
        cin >> from;
        bool isPossible = false;
        for (size_t j = 1; j < L; ++j) {
            cin >> to;
            isPossible = false;
            for (const auto &possibility: townMap[from][to]) {
                if (!numbers[possibility]) {
                    isPossible = true;
                    break;
                }
            }
            if (!isPossible) {
                for (size_t k = j + 1; k < L; ++k) {
                    cin >> to;
                }
                break;
            }
            from = to;
        }
        cout << isPossible;
    }

    return 0;
}
