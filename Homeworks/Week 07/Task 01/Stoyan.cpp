#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;


int main() {
    set<size_t> binaryNumbers;
    size_t N, number;
    cin >> N;
    
    for (size_t i = 0; i < N; i++) {
        cin >> number;
        for (size_t j = 0; j <= number; j++) {
            if ((number | j) == number)
                binaryNumbers.insert(j);
        }
    }
  
    cout << binaryNumbers.size();
    return 0;
}
