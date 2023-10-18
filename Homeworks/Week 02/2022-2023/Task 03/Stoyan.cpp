#include <vector>
#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    size_t symbols[256] = {0};

    for (size_t i = 0; i < S.size(); i++) {
        symbols[S[i]]++;
    }

    for (size_t i = 0; i < S.size(); i++) {
        if (symbols[S[i]] == 1) {
            cout << i << " ";
        }
    }

    return 0;
}
