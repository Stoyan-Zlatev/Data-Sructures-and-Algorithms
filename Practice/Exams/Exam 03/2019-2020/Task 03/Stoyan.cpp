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

    void deletePenultimateAndPrint() {
        deleteChildrenLeaves(root);
        printSorted(root);
    }

    bool hasChildren(Node *root) {
        return root->left != NULL || root->right != NULL;
    }

    void printSorted(Node *root) {
        if (root == NULL)
            return;

        printSorted(root->left);
        cout << root->value << " ";
        printSorted(root->right);
    }

private:
    Node *deleteChildrenLeaves(Node *root) {
        if (root == NULL || (root->right == NULL && root->left == NULL)) {
            return root;
        }
        if (root->left == NULL) {
            if (!hasChildren(root->right)) {
                Node *temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            root->right = deleteChildrenLeaves(root->right);
        } else if (root->right == NULL) {
            if (!hasChildren(root->left)) {
                Node *temp = root->left;
                delete root;
                root = temp;
                return root;
            }
            root->left = deleteChildrenLeaves(root->left);
        } else {
            if (!hasChildren(root->left) && !hasChildren(root->right)) {
                root->right->left = root->left;
                Node *temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            root->right = deleteChildrenLeaves(root->right);
            root->left = deleteChildrenLeaves(root->left);
        }

        return root;
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
    tree.deletePenultimateAndPrint();
    return 0;
}