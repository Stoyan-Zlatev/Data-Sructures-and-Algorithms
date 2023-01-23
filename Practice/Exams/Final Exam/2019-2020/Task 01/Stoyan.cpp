#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, size_t> numbersMap;

int main() {
    size_t N, M;
    cin >> N >> M;
    vector<long long> arr1(N);
    vector<long long> arr2(M);
    vector<long long> temp(M);

    for (size_t i = 0; i < N; ++i) {
        cin >> arr1[i];
    }
    for (size_t i = 0; i < M; ++i) {
        cin >> arr2[i];
        temp[i] = arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    size_t index = 0;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = index; j < N; ++j, ++index) {
            if (arr1[j] >= arr2[i]) {
                break;
            }
        }
        numbersMap[arr2[i]] = index;
    }

    for (size_t i = 0; i < M; ++i) {
        cout << numbersMap[temp[i]] << " ";
    }

    return 0;
}
