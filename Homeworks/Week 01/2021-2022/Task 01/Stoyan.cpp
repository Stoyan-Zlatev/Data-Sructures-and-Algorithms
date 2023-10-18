#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string word;
    cin >> word;

    char variant;
    cin >> variant;

    vector<int> indexes;
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] == variant) {
            indexes.push_back(i);
        }
    }

    size_t minDistance;
    for (int i = 0; i < word.size(); i++) {
        minDistance = INTMAX_MAX;
        for (int index: indexes) {
            minDistance = (abs(index - i) < minDistance) ? abs(index - i): minDistance;
        }
        cout << minDistance << " ";
    }

    return 0;
}
