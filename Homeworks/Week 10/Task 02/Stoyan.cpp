#include <bits/stdc++.h>

using namespace std;

unordered_map<char, set<char>> graph;
bool visited[CHAR_MAX + 1];

stack<char> letters;

void dfs(const char& value) {
    visited[value] = true;

    if(graph.count(value)){
        for (const auto& element : graph[value]) {
            if (!visited[element]) {
                dfs(element);
            }
        }
    }
    letters.push(value);
}

void topologicalSort() {
    for (const auto& element : graph) {
        if (!visited[element.first]) {
            dfs(element.first);
        }
    }
}

int main() {
    size_t N;
    cin >> N;

    string first, second;
    cin >> first;
    for (size_t i = 1; i < N; ++i) {
        cin >> second;
        for (size_t j = 0; j < first.size() && j < second.size(); ++j) {
            if (first[j] != second[j]) {
                graph[first[j]].insert(second[j]);
                break;
            }
        }
        first = second;
    }

    topologicalSort();
    while (!letters.empty()) {
        cout << letters.top() << " ";
        letters.pop();
    }

    return 0;
}
