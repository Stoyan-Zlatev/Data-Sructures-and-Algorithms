#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, bool> visited;
unordered_map<size_t, bool> currentVisited;

int main() {
    size_t N, M, number, sum = 0;
    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        visited[number] = true;
    }

    cin >> M;
    for (size_t i = 0; i < M; ++i) {
        cin >> number;
        if (visited[number] && !currentVisited[number]) {
            sum += number;
        }

        currentVisited[number] = true;

    }

    cout << sum;
    return 0;
}
