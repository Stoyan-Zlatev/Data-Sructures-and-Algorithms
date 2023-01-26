#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *leftNode;
    Node *rightNode;

    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node *cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    bool firstPrint = true;

    void print(Node *root) {
        if (root == NULL) {
            return;
        }

        print(root->rightNode);
        print(root->leftNode);
        if (firstPrint) {
            cout << root->data;
            firstPrint = false;
        } else {
            cout << ";" << root->data;
        }
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.print(root);
    return 0;
}
