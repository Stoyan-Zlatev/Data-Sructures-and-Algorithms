#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data) : data(data) {

    }
};

Node *root = nullptr;

void print_odd_layers(Node *root) {
    queue < Node * > layers;
    layers.push(root);
    size_t layer = 1;
    while (!layers.empty()) {
        size_t levelSize = layers.size();
        for (size_t i = 0; i < levelSize; ++i) {
            Node *current = layers.front();
            if ((layer & 1)) {
                cout << current->data << " ";
            }
            if (current->left) {
                layers.push(current->left);
            }
            if (current->right) {
                layers.push(current->right);
            }
            layers.pop();
        }
        layer++;
    }
}

void find(Node *&current, Node *&parent, int X) {
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

void remove(Node *&root, int X) {
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
        } else {
            root = nullptr;
        }
        free(current);
    } else if (current->left && current->right) {
        Node *successor = findSuccessor(current->right);
        int value = successor->data;
        remove(root, value);
        current->data = value;
    } else {
        Node *child = (current->left ? current->left : current->right);
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
        } else if (command == "remove") {
            cin >> value;
            remove(root, value);
        } else if (command == "print_odd_layers") {
            print_odd_layers(root);
        }
    }
    return 0;
}
