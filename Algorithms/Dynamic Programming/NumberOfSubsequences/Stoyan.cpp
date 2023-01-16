#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N;
    cin >> N;

    string word;
    cin >> word;

    size_t e=1, a=0, ab=0, abc=0;

    for (int i = 0; i < N; ++i) {
        if (word[i] == 'a') {
            a += e;
        } else if (word[i] == 'b') {
            ab += a;
        } else if (word[i] == 'c') {
            abc += ab;
        } else if (word[i] == '?') {
            abc = 3*abc +ab;
            ab = 3*ab + a;
            a = 3*a + e;
            e = 3*e;
        }
    }

    cout << abc;
}
