#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

size_t prices[100000];

int main() {
    size_t count;
    std::cin >> count;
    
    for(size_t i = 0; i < count; i++) {
        std::cin >> prices[i];
    }
    
    size_t win = 0;
    for(size_t i = 1; i < count; i++) {
        if(prices[i] > prices[i - 1]) {
            win += (prices[i] - prices[i - 1]);
        }
    }
    
    std::cout << win;
}
