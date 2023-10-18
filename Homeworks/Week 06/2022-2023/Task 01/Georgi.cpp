#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

long sumContainer[20000000] = {0};
size_t minIndex = 10000000;
size_t maxIndex = 10000000;
Node nodesContainer[1000000];

void sumColumns(Node* root, size_t index){
    if(!root)
        return;
    
    sumContainer[index] += root->value;
    if(index < minIndex)
        minIndex = index;
    if(maxIndex < index)
        maxIndex = index;
    sumColumns(root->left, index - 1);
    sumColumns(root->right, index + 1);
}


int main() {
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        int value, leftIndex, rightIndex;
        std::cin >> value >> leftIndex >> rightIndex;
        
        nodesContainer[i].value = value;
        nodesContainer[i].left = leftIndex == -1 ? nullptr : &nodesContainer[leftIndex];
        nodesContainer[i].right = rightIndex == -1 ? nullptr : &nodesContainer[rightIndex];
    }
    
    sumColumns(&nodesContainer[0], minIndex);
    
    for(size_t i = minIndex; i <= maxIndex; i++)
        if(sumContainer[i] != 0)
            std::cout << sumContainer[i] << " ";
        
    return 0;
}