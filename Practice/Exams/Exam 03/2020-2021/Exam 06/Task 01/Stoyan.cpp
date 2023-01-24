#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

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

    void printSFB() {
        print(root);
    }

    void print(Node *root) {
        deque < Node * > dq;
        dq.push_back(root);
        int depth = 0;
        while (!dq.empty()) {
            size_t levelSize = dq.size();
            if (depth & 1) {
                for (int i = 0; i < levelSize; ++i) {
                    Node *current = dq.back();
                    if (current->right) {
                        dq.push_front(current->right);
                    }
                    if (current->left) {
                        dq.push_front(current->left);
                    }
                    cout << current->value << " ";
                    dq.pop_back();
                }
            } else {
                for (int i = 0; i < levelSize; ++i) {
                    Node *current = dq.front();
                    if (current->left) {
                        dq.push_back(current->left);
                    }
                    if (current->right) {
                        dq.push_back(current->right);
                    }
                    cout << current->value << " ";
                    dq.pop_front();
                }
            }
            depth++;
        }
    }

private:
    //you can write helper functions if needed
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

    tree.printSFB();
    return 0;
}