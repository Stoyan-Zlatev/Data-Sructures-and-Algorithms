https://docs.google.com/document/d/1FEty_lp3LljLMHJcHunXFwL2mxxM1UuB/edit
#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t stairs;
    cin >> stairs;

    size_t stairsBuffer[stairs + 1];
    stairsBuffer[0] = 1;
    stairsBuffer[1] = 1;
    stairsBuffer[2] = 2;

    for (int i = 3; i <= stairs; ++i) {
        stairsBuffer[i] = stairsBuffer[i-1] + stairsBuffer[i-2] + stairsBuffer[i-3];
    }

    cout << stairsBuffer[stairs];
}
