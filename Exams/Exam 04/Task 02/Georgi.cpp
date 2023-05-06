#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    size_t n, m;
    std::cin >> n >> m;
    
    priority_queue<size_t, vector<size_t>, greater<size_t>> powers;
    
    for(size_t i = 0; i < n; i++) {
        size_t power;
        std::cin >> power;
        powers.push(power);
    }
    
    if(powers.top() >= m){
        std::cout << 0;
        return 0;
    }
    
    size_t current = 0;
    bool achieved = false;
    while(true){
        if(powers.size() < 2){
            break;
        }
        size_t w1 = powers.top();
        powers.pop();
        size_t w2 = powers.top();
        powers.pop();
        
        size_t newW = w1 + 2 * w2;
        powers.push(newW);
        current++;
        if(powers.top() >= m){
            achieved = true;
            break;
        }
        
    }
    
    if(achieved){
        std::cout << current;
    } else {
        std::cout << -1;
    }
    
    return 0;
}