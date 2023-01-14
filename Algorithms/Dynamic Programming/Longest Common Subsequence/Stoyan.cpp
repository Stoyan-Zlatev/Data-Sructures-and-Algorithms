#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, unordered_map<size_t, size_t>> wordMap;

size_t solve(string &word1, string &word2, size_t length1, size_t length2) {
    if (length1 == 0 || length2 == 0) {
        return 0;
    }

    if (wordMap.find(length1) != wordMap.end() && wordMap[length1].find(length2) != wordMap[length1].end()) {
        return wordMap[length1][length2];
    }

    if (word1[length1 - 1] == word2[length2 - 1]) {
        wordMap[length1][length2] = 1 + solve(word1, word2, length1 - 1, length2 - 1);
    } else {
        wordMap[length1][length2] = max(solve(word1, word2, length1 - 1, length2),
                                        solve(word1, word2, length1, length2 - 1));
    }

    return wordMap[length1][length2];
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    size_t length1 = word1.size(), length2 = word2.size();

    cout << solve(word1, word2, length1, length2);
}
