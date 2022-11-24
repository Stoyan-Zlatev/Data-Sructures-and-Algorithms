#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    size_t value;
    Node *left;
    Node *right;

    Node(size_t value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *connect(Node *root, size_t number) {
    if (root == nullptr) {
        return new Node(number);
    }

    if (number > root->value) {
        root->right = connect(root->right, number);
    }
    if (number < root->value) {
        root->left = connect(root->left, number);
    }
    return root;
}

bool hasTwoChildren(Node* root) {
    return root->left && root->right;
}


void printLeaves(Node* root) {
    if (root == NULL)
        return;
    if (hasTwoChildren(root))
        cout << root->value << " ";
    printLeaves(root->left);
    printLeaves(root->right);
}

int main() {
     std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t T, N;
    cin >> T;
    
    for (size_t i = 0; i < T; i++) {    
        cin >> N;
        size_t number;
        cin >> number;
        Node *root = new Node(number);
        for (size_t i = 1; i < N; i++) {
            cin >> number;
            connect(root, number);
        }
        printLeaves(root);
        cout << '\n';
    }
    return 0;
}
