#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data) {
        this->data = data;
    }
};

Node *insert(Node *root, int X) {
    if (root == nullptr) {
        return new Node(X);
    }

    if (X < root->data) {
        root->left = insert(root->left, X);
    } else if (X > root->data) {
        root->right = insert(root->right, X);
    }

    return root;
}

void inorder(Node *root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    size_t N, X;
    cin >> N;
    string command;
    Node *root = nullptr;
    for (size_t i = 0; i < N; ++i) {
        cin >> command;
        if (command == "add") {
            cin >> X;
            root = insert(root, X);
        } else if (command == "inorder") {
            inorder(root);
            cout << '\n';
        }
    }

    return 0;
}
