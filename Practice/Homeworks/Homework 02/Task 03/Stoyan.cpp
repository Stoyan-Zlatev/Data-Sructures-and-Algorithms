#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    size_t N;
    cin >> N;

    vector<char> digits;
    vector<char> lowers;
    vector<char> alphas;

    char el;
    for (int i = 0; i < N; ++i) {
        cin >> el;
        if (isdigit(el)) {
            digits.push_back(el);
        } else if (islower(el)) {
            lowers.push_back(el);
        } else {
            alphas.push_back(el);
        }
    }
    std::sort(digits.begin(), digits.end());
    std::sort(lowers.begin(), lowers.end());
    std::sort(alphas.begin(), alphas.end());

    for (int i = 0; i < digits.size(); ++i) {
        cout << digits[i];
    }

    for (int i = 0; i < lowers.size(); ++i) {
        cout << lowers[i];
    }

    for (int i = 0; i < alphas.size(); ++i) {
        cout << alphas[i];
    }
    return 0;
}
