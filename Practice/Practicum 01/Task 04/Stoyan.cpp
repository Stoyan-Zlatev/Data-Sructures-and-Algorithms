#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    int N, M;
    int copiesMade;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        copiesMade = M - 1;
        if ((copiesMade <= N && copiesMade > 0) &&
            (N % 2 == copiesMade % 2) ||
            (N == 0 && copiesMade == 0)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
