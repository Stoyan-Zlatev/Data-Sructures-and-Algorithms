#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;

struct Node {
    char value = '-';
    vector<short> nodes; // 0 - 25
};

vector<Node> container(26);

void compare(string& s1, string& s2) {
    size_t i = 0, j = 0;
    while (i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
        i++;
        j++;
    }

    if (i < s1.size() && j < s2.size()) {
        container[s1[i] - 'a'].value = s1[i];
        container[s1[i] - 'a'].nodes.push_back(s2[j] - 'a');
    }
}

void topologicalSort(short node, bool visited[], stack<char>& result) {
    visited[node] = true;

    for (size_t i = 0; i < container[node].nodes.size(); i++) {
        if (!visited[container[node].nodes[i]]) {
            topologicalSort(container[node].nodes[i], visited, result);
        }
    }

    result.push(node + 'a');
}

int main() {
    vector<string> wordsContainer;

    short n;
    cin >> n;
    for (short i = 0; i < n; i++) {
        string current;
        cin >> current;
        wordsContainer.push_back(current);
    }

    for (short i = 0; i < wordsContainer.size() - 1; i++) {
        compare(wordsContainer[i], wordsContainer[i + 1]);
    }

    stack<char> result;
    bool visited[26] = { false };
    for (size_t i = 0; i < 26; i++) {
        if (container[i].value != '-' && !visited[i]) {
            topologicalSort(i, visited, result);
        }
    }

    while (!result.empty()) {
        cout << result.top() << ' ';
        result.pop();
    }

    return 0;
}