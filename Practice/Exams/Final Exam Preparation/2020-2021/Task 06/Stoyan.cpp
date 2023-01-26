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

void find(Node *&current, Node *&parent, int X) {
    if (current == nullptr) {
        return;
    }

    while (current && current->data != X) {
        parent = current;

        if (X < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

Node *findSuccessor(Node *current) {
    while (current->left) {
        current = current->left;
    }

    return current;
}

void del(Node *&root, int X) {
    Node *parent = nullptr;
    Node *current = root;

    find(current, parent, X);

    if (current == nullptr) {
        return;
    }

    if (current->left == nullptr && current->right == nullptr) {
        if (current != root) {
            if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }

            free(current);
        } else {
            root = nullptr;
        }
    } else if (current->left && current->right) {
        Node *successor = findSuccessor(current->right);
        int val = successor->data;
        del(root, val);
        current->data = val;
    } else {
        Node *child = current->left ? current->left : current->right;

        if (current != root) {
            if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        free(current);
    }
}

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
        } else if (command == "del") {
            cin >> X;
            del(root, X);
        }
    }

    return 0;
}
