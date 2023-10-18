#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t N;
    cin >> N;

    vector<int> numbers;
    //Add the border between positive and negative numbers
    numbers.push_back(0);

    int currentNumber;
    for (int i = 0; i < N; i++) {
        cin >> currentNumber;
        if (currentNumber > 0) {
            numbers.push_back(currentNumber);
        }
    }

    //Remove duplicate shirt numbers
    std::sort(numbers.begin(), numbers.end());
    std::unique(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] + 1 != numbers[i + 1]){
            cout << numbers[i] + 1;
            return 0;
        }
    }

    //If we reached here - all the numbers were consecutive
    cout << numbers.back() + 1;
    return 0;
}
