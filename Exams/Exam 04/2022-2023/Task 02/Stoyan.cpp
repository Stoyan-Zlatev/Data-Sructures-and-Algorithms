#include <bits/stdc++.h>
using namespace std;

priority_queue<size_t, vector<size_t>, greater<size_t>> legos;

int main() {
    size_t N, M, lego;
    cin >> N >> M;
    
    for (size_t i = 0; i < N;i++) {
        cin >> lego;
        legos.push(lego);
    }
    
    size_t rounds = 0;
    size_t first, second;
    while(true) {
        if (legos.top() > M)
            break;
        if (legos.empty()) {
            cout << -1;
            return 0;
        }
        
        first = legos.top();
        legos.pop();
        if (!legos.empty()) {
         second = legos.top();
          legos.pop();
        } else {
             cout << -1;
            return 0;
        }
        
        rounds++;
        legos.push(first + 2*second);
    }

    cout << rounds;
    return 0;
}
