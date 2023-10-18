#include <bits/stdc++.h>
using namespace std;

map<string, size_t> wordMap;

int main() {
   string word;
    while (cin>>word) {
        wordMap[word]++;
    }

    
    for (const auto& element: wordMap) {
        if (element.second == 1) {
            cout << element.first << '\n';
        }
    }
    return 0;
}
