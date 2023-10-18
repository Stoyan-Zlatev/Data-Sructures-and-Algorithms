#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    long long N;
    cin >> N;
    
    string word1;
    cin >> word1;

    string word2;
    cin >> word2;
    
    if (word1.size() != word2.size()) {
        cout << "no";
    }

    long long arr[26];
    for (int i = 0; i < 26; ++i) {
        arr[i] = 0;
    }
    
    for (int i = 0; i < N; ++i) {
        arr[int(word1[i]) - 'a']++;
    }

    for (int i = 0; i < N; ++i) {
        arr[int(word2[i]) - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
        if (arr[i] != 0) {
            cout << "no";
            return 0;
        }
    }

    cout << "yes";
    return 0;
}
