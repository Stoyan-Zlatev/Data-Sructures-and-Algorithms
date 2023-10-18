#include <bits/stdc++.h>

using namespace std;

map<vector<size_t>, size_t> counter;

int main() {
    size_t N, M;
    cin >> N >> M;
    vector<vector<size_t>> arr(N, vector<size_t>(M));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
        counter[arr[i]]++;
    }

    size_t count = 0;
    for (const auto& element:arr) {
        if (counter[element] == 1) {
            count++;
        }
    }

    cout << count;
    return 0;
}
