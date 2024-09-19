#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char arr[1000000 + 1];

int main() {
    size_t count;
    std::cin >> count;
    for(size_t i = 0; i < count; i++) {
        size_t length;
        std::cin >> length >> arr;
        
        size_t result = 0;
        for(size_t i = 1; i < length; i++) {
            if(arr[i - 1] == arr[i]) {
                result++;
            }
        }
        
        std::cout << result << std::endl;
    } 
}
