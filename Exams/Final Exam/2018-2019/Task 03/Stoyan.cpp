#include <bits/stdc++.h>

using namespace std;

unordered_map <string, size_t> wordMap;

int main() {
    string s1;
    while (cin >> s1) {
        wordMap[s1]++;
    }
    vector <string> words;
    for (const auto &element: wordMap) {
        if (element.second == 1) {
            words.push_back(element.first);
        }
    }

    sort(words.begin(), words.end());
    for (const auto &word: words) {
        cout << word << '\n';
    }
    return 0;
}
