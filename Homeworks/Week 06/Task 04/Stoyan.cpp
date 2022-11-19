#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    string value;
    Node *left;
    Node *right;

    Node(string value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *connect(Node *root, string word) {
    if (root == nullptr) {
        return new Node(word);
    }

    if (word > root->value) {
        root->right = connect(root->right, word);
    }
    if (word < root->value) {
        root->left = connect(root->left, word);
    }
    return root;
}

bool containsWord = true;

void contains(Node *root, string word) {
    if (root == nullptr) {
        containsWord = false;
        return;
    }

    if (word > root->value) {
        contains(root->right, word);
    }
    if (word < root->value) {
         contains(root->left, word);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N, Q;
    cin >> N;
    string word;
    cin >> word;
    Node *root = new Node(word);
    for (size_t i = 1; i < N; i++) {
        cin >> word;
        connect(root, word);
    }
    
    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        cin >> word;
        contains(root, word);
        if (containsWord)
            cout << "YES\n";
        else
            cout << "NO\n";
        containsWord=true;
    }
    return 0;
}
