#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue <size_t> q;
    size_t N, number;
    cin >> N;

    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        q.push(number);
    }

    unordered_map <size_t, size_t> numbersMap;
    size_t counter = 0;
    for (size_t i = 0; i < N; ++i) {
        numbersMap[q.front()]++;
        q.pop();
        cin >> number;
        if (numbersMap.find(number) == numbersMap.end() || numbersMap[number] == 0) {
            counter++;
        } else {
            numbersMap[number]--;
        }
    }

    cout << counter;
    return 0;
}