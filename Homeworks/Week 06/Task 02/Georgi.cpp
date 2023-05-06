#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};


bool isMaxNodeLower(Node* root, int value) {
    if(!root)
        return true;
    
    while(root->right){
        root = root->right;
    }

    return root->value < value;
}

bool isMinNodeLower(Node* root, int value) {
    if(!root)
        return true;
    
    while(root->left){
        root = root->left;
    }

    return root->value > value;
}

bool isValidBST(Node* root) {
    if (!root) {
        return true;
    }

    return isMaxNodeLower(root->left, root->value) && isMinNodeLower(root->right, root->value) && isValidBST(root->left) && isValidBST(root->right);
}

Node nodesContainer[3000000];

int main() {
    int treesCount;
    std::cin >> treesCount;

    for (int j = 0; j < treesCount; j++) {
        int nodesCount;
        std::cin >> nodesCount;

        for (int i = 0; i < nodesCount; i++) {
            int value, leftIndex, rightIndex;
            std::cin >> value >> leftIndex >> rightIndex;

            nodesContainer[i].value = value;
            nodesContainer[i].left = leftIndex == -1 ? nullptr : &nodesContainer[leftIndex];
            nodesContainer[i].right = rightIndex == -1 ? nullptr : &nodesContainer[rightIndex];
        }

        std::cout << isValidBST(&nodesContainer[0]) << '\n';
    }

    return 0;
}