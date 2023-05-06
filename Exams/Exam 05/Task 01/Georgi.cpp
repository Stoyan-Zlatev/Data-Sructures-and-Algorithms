#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

int main() {
    std::map<std::string, size_t> counter;
    std::string input;
    while(std::cin >> input) {
        counter[input]++;
    }
    
    for(auto& kvp: counter) {
        if(kvp.second == 1) {
            std::cout << kvp.first << '\n';
        }
    }
    
    return 0;
}