#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    size_t days;
    std::cin >> days;
    std::vector<size_t> stickers(days);
    
    for(size_t i = 0; i < days; i++) {
        std::cin >> stickers[i];
    }
    
    size_t result = 0;
    std::unordered_map<size_t, size_t> container;
    for(size_t i = 0; i < days; i++) {
        container[stickers[i]]++;
        size_t current;
        std::cin >> current;
        
        if(container[current] == 0) {
            result++;
        }
        else {
            container[current]--;
        }
    }
    
    std::cout << result;
    
    return 0;
}