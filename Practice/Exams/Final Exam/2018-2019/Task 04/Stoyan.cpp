#include <bits/stdc++.h>

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


    void printLeftProfile() {
        Node *current = root;
        queue < Node * > levels;
        levels.push(current);
        while (!levels.empty()) {
            size_t levelSize = levels.size();
            cout << levels.front()->value << " ";
            for (size_t i = 0; i < levelSize; ++i) {
                Node *top = levels.front();
                levels.pop();
                if (top->left) {
                    levels.push(top->left);
                }
                if (top->right) {
                    levels.push(top->right);
                }
            }
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
    tree.printLeftProfile();
    return 0;
}