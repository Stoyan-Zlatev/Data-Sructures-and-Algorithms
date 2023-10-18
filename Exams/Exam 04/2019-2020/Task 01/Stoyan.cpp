#include <bits/stdc++.h>

using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N;
    long long number;
    priority_queue <size_t, vector<size_t>, greater<size_t>> ranks;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> number;
        if (number != -1)
            ranks.push(number);
        else if (!ranks.empty()) {
            cout << ranks.top() << " ";
            ranks.pop();
        }
    }

    return 0;
}