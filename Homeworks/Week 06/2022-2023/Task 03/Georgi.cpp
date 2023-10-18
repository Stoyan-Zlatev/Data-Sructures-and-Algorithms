#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* parent = nullptr;
};

Node nodesContainer[1000000];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int nodesCount;
    std::cin >> nodesCount;

    nodesContainer[0].value = 0;
    for (int i = 0; i < nodesCount - 1; i++) {
        int parent, child;
        std::cin >> parent >> child;
        nodesContainer[child].parent = &nodesContainer[parent];
        nodesContainer[child].value = child;
        nodesContainer[parent].value = parent;
    }

    int queriesCount;
    std::cin >> queriesCount;
    for (int i = 0; i < queriesCount; i++) {
        int parent, child;
        std::cin >> parent >> child;

        Node* parentNode = &nodesContainer[parent];
        Node* iter = &nodesContainer[child];
        while (iter != nullptr) {
            if (iter == parentNode) {
                break;
            }
            if(iter->value < parentNode->value){
                iter = nullptr;
                break;
            }
            iter = iter->parent;
        }

        std::cout<< (iter ? "YES" : "NO") << '\n';
    }

    return 0;
}