#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MOD = 1e9 + 7;

size_t populateFlowers(size_t n) {
    if(n == 1 || n == 2) {
        return 2;
    }
    
    size_t first = 2;
    size_t second = 2;
    
    for(size_t i = 3; i <= n; i++) {
        size_t temp = second;
        second += first;
        first = temp;
        second %= MOD;
        first %= MOD;
    }
    
    return second;
}


int main() {
    size_t flowersCount;
    std::cin >> flowersCount;
    
    size_t result = populateFlowers(flowersCount);
    
    std::cout << result;
    
    return 0;
}