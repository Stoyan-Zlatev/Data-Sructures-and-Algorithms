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

    int left = 0, right = 0;

    void leftRight(Node *root, char direction = ' ') {
        if (root == NULL) {
            return;
        }

        if (direction == 'L') {
            left++;
        } else if (direction == 'R') {
            right++;
        }

        leftRight(root->leftNode, 'L');
        leftRight(root->rightNode, 'R');
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

    myTree.leftRight(root);
    cout << "[" << myTree.left << "," << myTree.right << "]";
    return 0;
}