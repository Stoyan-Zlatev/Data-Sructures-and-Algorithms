#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;

    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB(size_t k) {
        printDistance(root, 0, k);
    }

private:
    void printDistance(Node *root, size_t distance, size_t k) {
        if (root == NULL)
            return;

        printDistance(root->right, distance + 1, k);
        if (distance == k) {
            cout << root->value << " ";
            return;
        }
        printDistance(root->left, distance + 1, k);
    }

    Node *root;

    Node *insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    size_t k;
    cin >> k;
    tree.printSFB(k);
    return 0;
}