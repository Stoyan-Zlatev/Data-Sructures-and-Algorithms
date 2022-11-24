#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    size_t value;
    Node *left;
    Node *right;

    Node(size_t value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *connect(Node *root, size_t number) {
    if (root == nullptr) {
        return new Node(number);
    }

    if (number > root->value) {
        root->right = connect(root->right, number);
    }
    if (number < root->value) {
        root->left = connect(root->left, number);
    }
    return root;
}

int main() {
      std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t T, N;
    cin >> T;
    
    for (size_t i = 0; i < T; i++) {    
        cin >> N;
        size_t number;
        size_t leftCounter = 0, rightCounter = 0;
        stack<size_t> leftTree;
        queue<size_t> rightTree;
        cin >> number;
        Node *root = new Node(number);
        for (size_t i = 1; i < N; i++) {
            cin >> number;
            connect(root, number);
        }
        queue<pair<Node*, int>> nodes;
        nodes.push(make_pair(root, 0));
        while(!nodes.empty()) {
            Node* current = nodes.front().first;
            int currentColumn = nodes.front().second;
            nodes.pop();
           if ((currentColumn < 0) && leftCounter < abs(currentColumn)) {
            leftCounter++;
            leftTree.push(current->value);
            } 
            if ( (currentColumn > 0) && rightCounter < (currentColumn)) {
                rightCounter++;
                rightTree.push(current->value);
            }
            if (current->left != NULL)
                nodes.push(make_pair(current->left, currentColumn - 1));
            if (current->right != NULL)
                nodes.push(make_pair(current->right, currentColumn + 1));
        }
         while (!leftTree.empty()) {
        cout << leftTree.top() << " ";
        leftTree.pop();
        }

        cout << root->value << " ";

        while (!rightTree.empty()) {
            cout << rightTree.front() << " ";
            rightTree.pop();
        }
         cout << "\n";   
    }

   
    return 0;
}
