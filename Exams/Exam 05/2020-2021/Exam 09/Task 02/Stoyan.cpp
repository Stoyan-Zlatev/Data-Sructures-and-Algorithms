#include <bits/stdc++.h>

using namespace std;

unordered_map <size_t, vector<size_t>> townMap;
unordered_map<size_t, bool> visited;
size_t componentCounter = 0;
size_t counter = 0;

void dfs(size_t value) {
    counter++;
    visited[value] = true;

    for (const size_t &element: townMap[value]) {
        if (!visited[element]) {
            dfs(element);
        }
    }
}

int main() {
    size_t N, M, start, end;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++) {
        cin >> start >> end;
        townMap[start].push_back(end);
        townMap[end].push_back(start);
    }

    for (size_t i = 0; i < N; i++) {
        if (!visited[i]) {
            counter = 0;
            dfs(i);
            if (counter >= 2) {
                componentCounter++;
            }
        }
    }

    cout << componentCounter;
    return 0;
}
