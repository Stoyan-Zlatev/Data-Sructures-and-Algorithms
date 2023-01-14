//Longest increasing subsequence
#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N, ans;
    cin >> N;

    size_t arr[N];
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    size_t sequenceMap[N];
    sequenceMap[0] = 1;
    for (int i = 1; i < N; ++i) {
        sequenceMap[i] = 1;
        for (int j = 0; j < i - 1; ++j) {
            if (arr[i] > arr[j]) {
                sequenceMap[i] = max(sequenceMap[i], sequenceMap[j] + 1);
            }
        }
        ans = max(ans, sequenceMap[i]);
    }

    cout << ans;
}
