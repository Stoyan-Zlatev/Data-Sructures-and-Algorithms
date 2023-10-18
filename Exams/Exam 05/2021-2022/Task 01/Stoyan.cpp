#include <bits/stdc++.h>
using namespace std;

unordered_map<string, size_t> wordCounter;

int main() {
    size_t N;
    cin >> N;
    
    string word;
    queue<string> words;
    for (size_t i = 0; i < N; i++) {
        cin >> word;
        wordCounter[word]++;
        words.push(word);
    }
    
    while (!words.empty()) {
        cout << wordCounter[words.front()] << " ";
        words.pop();
    }
    return 0;
}
