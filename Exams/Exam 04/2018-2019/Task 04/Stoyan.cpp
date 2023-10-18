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


    void count(Node *root) {
        queue < Node * > q;
        q.push(root);
        vector<int> levels;
        while (!q.empty()) {
            int levelSize = q.size();
            levels.push_back(levelSize);
            for (int i = 0; i < levelSize; ++i) {
                auto current = q.front();
                q.pop();
                if (current->leftNode) {
                    q.push(current->leftNode);
                }
                if (current->rightNode) {
                    q.push(current->rightNode);
                }
            }
        }

        if (levels.size()) {
            cout << levels[0];
        }

        for (int i = 1; i < levels.size(); ++i) {
            cout << ";" << levels[i];
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

    myTree.count(root);
    return 0;
}