#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

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

void levelorder(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue < Node * > nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        size_t levelSize = nodes.size();
        for (size_t i = 0; i < levelSize; ++i) {
            Node *current = nodes.front();
            if (current->left) {
                nodes.push(current->left);
            }
            if (current->right) {
                nodes.push(current->right);
            }
            cout << current->data << " ";
            nodes.pop();
        }
    }
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
        } else if (command == "levelorder") {
            levelorder(root);
            cout << '\n';
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
