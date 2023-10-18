#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data) : data(data) {

    }
};

Node *root = nullptr;

void add(int X) {
    if (root == NULL) {
        root = new Node(X);
    }
    Node *current = root;

    while (true) {
        if (X == current->data) {
            break;
        } else if (X > current->data) {
            if (current->right) {
                current = current->right;
            } else {
                current->right = new Node(X);
                break;
            }
        } else {
            if (current->left) {
                current = current->left;
            } else {
                current->left = new Node(X);
                break;
            }
        }
    }
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    size_t N, value;
    cin >> N;
    string command;
    for (size_t i = 0; i < N; ++i) {
        cin >> command;
        if (command == "print") {
            printTree(root);
        } else if (command == "add") {
            cin >> value;
            add(value);
        }
    }
    return 0;
}
