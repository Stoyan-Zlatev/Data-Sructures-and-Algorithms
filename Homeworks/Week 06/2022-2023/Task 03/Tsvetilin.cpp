#include <vector>
#include <iostream>

struct Node{
    size_t value;
    size_t timeIn = 0;
    size_t timeOut = 0;
    std::vector<Node*> children;
};

const size_t MAX_SIZE = 1e6+1;
Node tree[MAX_SIZE];

size_t currentTime = 0;
void traverseDepth(Node* root) {
    
    root->timeIn = currentTime;
    currentTime++;
    
    for(auto child : root->children){
        traverseDepth(child);
    }
    
    currentTime++;
    root->timeOut = currentTime;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    size_t n;
    std::cin>>n;
    
    size_t x,y;
    
    for(size_t i = 0; i < n-1; ++i){
        std::cin>>x>>y;
        tree[x].children.push_back(tree+y);
    }
    
    Node* root = tree;
    traverseDepth(root);
    
    size_t q;
    std::cin>>q;
    
    for(size_t i = 0; i < q; ++i){
        std::cin>>x>>y;
        std::cout<<((tree[x].timeIn < tree[y].timeIn && tree[x].timeOut > tree[y].timeOut) ? "YES\n" : "NO\n" );
    }
    
    return 0;
}