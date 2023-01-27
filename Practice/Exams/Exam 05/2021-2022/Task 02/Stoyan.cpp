#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, size_t> numbers;

int main() {
    size_t N;
    cin >> N;
    
    long long number;
    unordered_set<long long> numbersSet;
    for (size_t i = 0; i < N; i++) {
        cin >> number;
        numbers[number]++;
        numbersSet.insert(number);
    }
    
    int sum = 0;
    for (const long long& number: numbersSet) {
        if (numbers[number] % 2 == 1)
            sum += (number * numbers[number]);
    }
    
    cout << sum;
    return 0;
}
