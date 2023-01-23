#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N;
    cin >> N;

    long long numbers[70000] = {0};
    long long number;
    for (int i = 0; i < N; ++i) {
        cin >> number;
        numbers[number] ++;
    }

    for (int i = 0; i < 70000; ++i) {
        if (numbers[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
