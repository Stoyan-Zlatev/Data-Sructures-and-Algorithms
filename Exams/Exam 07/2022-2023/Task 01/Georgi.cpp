#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

long long matrix[1000][1000] = {};
bool specialMatrix[1000][1000] = {};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    int specialCount;
    std::cin >> specialCount;
    
    for(int i = 0; i < specialCount; i++) {
        int k, j;
        std::cin >> k >> j;
        specialMatrix[k][j] = true;
    }
    
    for(int i = 1; i < n; i++) {
        matrix[0][i] += matrix[0][i-1];
        matrix[i][0] += matrix[i - 1][0];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            long long current = matrix[i][j];
            
            matrix[i][j] = std::max(matrix[i - 1][j] + current, matrix[i][j - 1] + current);
            if(specialMatrix[i][j]) {
                matrix[i][j] = std::max(matrix[i][j], matrix[i - 1][j- 1] + current);
            }
        }
    }
    
    std::cout << matrix[n - 1][n - 1];
    
    return 0;
}