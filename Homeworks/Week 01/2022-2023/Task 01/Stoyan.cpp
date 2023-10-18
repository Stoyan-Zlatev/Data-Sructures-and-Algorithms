#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    size_t Q, len, counter = 0;
    char current, previous;
    cin >> Q;

    for (size_t i = 0; i < Q; i++) {
        counter = 0;
        cin >> len >> current;
        previous = current;
        for (size_t j = 1; j < len; j++) {
            cin >> current;
            if (current == previous) {
                counter++;
            }

            previous = current;
        }
        cout << counter << endl;
    }
}
