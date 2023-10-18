#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val){
        this->value = val;
    }
};

Node* insert(Node* root, int key){
    if(!root)
        return new Node(key);
    
    if(root->value > key){
        root->left = insert(root->left, key);
    } else if(root->value < key){
        root->right = insert(root->right, key);
    }
    
    return root;
}

void print(Node* root){
    if(!root)
        return;
    
    if(root->right && root->left){
        cout << root->value << " ";
    }
    print(root->left);
    print(root->right);
}

int main() {
    int count;
    cin>>count;
    for(int i = 0; i < count; i++){
        int l;
        cin>>l;
        
        Node* root = nullptr;
        for(int j = 0; j < l; j++){
            int value;
            cin>>value;
                
            if(!root){
                root = new Node(value);
            } else {
                root = insert(root, value);
            }
        }
        
        print(root);
        cout<<"\n";
    }
    
    return 0;
}