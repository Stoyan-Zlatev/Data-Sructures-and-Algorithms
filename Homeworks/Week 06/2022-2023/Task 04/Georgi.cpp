#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    string value;
    Node* left;
    Node* right;
    
    Node(const string& value, Node* left = nullptr, Node* right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

// Works only if you have atleast one node
void insert(Node* root, const string& value){
    Node* iter = root;
    Node* prev = nullptr;
    while(iter){
        if(iter->value > value){
            prev = iter;
            iter = iter->left;   
        } else {
            prev = iter;
            iter = iter->right;   
        }
    }
    
    if(prev->value > value){
        prev->left = new Node(value);
    } else {
        prev->right = new Node(value);
        
    }
}

bool hasValue(Node* root, const string& value){
    if(!root)
        return false;
    
    if(root->value == value)
        return true;
    
    if(root->value > value)
        return hasValue(root->left, value);
    
    return hasValue(root->right, value);
}

int main() {
    int nodesCount;
    std::cin>> nodesCount;
    Node* root = nullptr;
    for(int i = 0; i < nodesCount; i++){
        string input;
        std::cin >> input;
        if(root == nullptr){
            root = new Node(input);
        } else {
            insert(root, input);
        }
    }
    
    int queriesCount;
    std::cin>> queriesCount;
    for(int i = 0; i < queriesCount; i++){
        string input;
        std::cin >> input;
        
        std::cout << (hasValue(root, input) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}