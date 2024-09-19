#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t numbersCounter[10000000 + 1]{};

int main() {
    size_t count;
    std::cin >> count;
    
    int current;
    for(size_t i = 0; i < count; i++) {
        std::cin >> current;
        if(current > 0) {
            numbersCounter[current]++;
        }
    }
    
    size_t missingNumber = count + 1;
    for(size_t i = 1; i <= count; i++) {
        if(numbersCounter[i] == 0) {
            missingNumber = i;
            break;
        }
    }
    std::cout << missingNumber;
}
