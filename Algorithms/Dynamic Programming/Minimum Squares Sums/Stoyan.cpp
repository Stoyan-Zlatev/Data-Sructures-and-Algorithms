https://docs.google.com/document/d/1W8b9K3WaCUoNMKvgvvqqggBybdYfvmGh/edit
#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N;
    cin >> N;

    vector<size_t> numbersMap(N+1, INT_MAX);
    for (int i = 0; i <= 3; ++i) {
        numbersMap[i] = i;
    }

    for (int i = 0; i*i <= N; ++i) {
        for (int j = 0; i*i + j <= N; ++j) {
            numbersMap[i*i + j] = min(numbersMap[i*i + j], 1 + numbersMap[j]);
        }
    }

    cout << numbersMap[N];
}
