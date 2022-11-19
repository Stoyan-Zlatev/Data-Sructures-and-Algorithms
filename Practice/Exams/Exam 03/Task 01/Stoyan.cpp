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

size_t sum = 0;

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }
    void sumLeaves(Node* root) {
        if (root->leftNode == nullptr && root->rightNode == nullptr && root->data % 2 == 1) {
            sum += root->data;
        }

        if (root->leftNode != nullptr)
            sumLeaves(root->leftNode);
        if (root->rightNode != nullptr)
            sumLeaves(root->rightNode);
    }

    void leaves(Node *root) {
        sumLeaves(root);
        cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}
