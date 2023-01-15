#include <bits/stdc++.h>

using namespace std;

unordered_map<char, size_t> wordMap;

bool isPossible(const unordered_map<char, size_t> &tempWordMap) {
    for (const auto &element: tempWordMap) {
        if (!(element.second & 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    string word;
    cin >> word;

    vector<size_t> subArrays(word.size() + 1, LLONG_MAX);
    subArrays[0] = 0;

    for (size_t i = 0; i < word.size() - 1; ++i) {
        if (subArrays[i] != LLONG_MAX) {
            wordMap.clear();
            for (size_t j = i; j < word.size(); ++j) {
                wordMap[word[j]]++;
                if (isPossible(wordMap)) {
                    subArrays[j + 1] = min(subArrays[i] + 1, subArrays[j + 1]);
                }
            }
        }
    }

    cout << subArrays[word.size()];
}
