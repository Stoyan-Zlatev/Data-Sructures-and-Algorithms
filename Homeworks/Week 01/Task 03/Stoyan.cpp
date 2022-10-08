#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t N;
    cin >> N;

    vector<int> ticketNumbers;
    //Add the border between positive and negative numbers
    ticketNumbers.push_back(0);

    int ticketNumber;
    for (size_t i = 0; i < N; i++) {
        cin >> ticketNumber;
        if (ticketNumber >= 0) {
            ticketNumbers.push_back(ticketNumber);
        }
    }

    std::sort(ticketNumbers.begin(), ticketNumbers.end());
    //Remove duplicate ticket numbers
    std::unique(ticketNumbers.begin(), ticketNumbers.end());
    bool isLast = true;
    for (size_t i = 0; i < ticketNumbers.size() - 1; ++i) {
        if (ticketNumbers[i] + 1 != ticketNumbers[i + 1]) {
            cout << ticketNumbers[i] + 1;
            return 0;
        }
    }

    //If we reached here - all the numbers were consecutive
    cout << ticketNumbers.back() + 1;
}
