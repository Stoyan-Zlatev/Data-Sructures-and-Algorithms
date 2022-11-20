#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int left = -1, right = -1;
};

const size_t MAX_SIZE = 1e5+1;
Node bst[MAX_SIZE];

void findKBiggestElement(int root, size_t k, stack<int> &indexes) {
    if (root == -1)
        return;

    findKBiggestElement(bst[root].right, k, indexes);

    if (indexes.size() >= k)
        return;

    indexes.push(root);
    findKBiggestElement(bst[root].left, k, indexes);
}

int removeKBiggestElement(size_t k) {
    stack<int> indexes;
    findKBiggestElement(0, k, indexes);
    int biggestIndex = indexes.top();
    indexes.pop();

    if ((bst[biggestIndex].left == -1 && bst[biggestIndex].right == -1) || indexes.empty()) {
        bst[biggestIndex].data = -1;
        return biggestIndex;
    }
    
    int secondBiggestIndex = bst[biggestIndex].right > -1 ? indexes.top() : bst[biggestIndex].left;

    bst[biggestIndex].data = bst[secondBiggestIndex].data;
    bst[secondBiggestIndex].data = -1;

    return secondBiggestIndex;
}

int main() {
    size_t N, K;
    cin >> N >> K;

    int element;
    for (int i = 0; i < N; ++i) {
        cin >> element;
        bst[i] = {element, 2 * i + 1 >= N ? -1 : 2 * i + 1, 2 * i + 2 >= N ? -1 : 2 * i + 2};
    }

    int biggestElementIndex = removeKBiggestElement(K);

    for (int i = 0; i < N; i++) {
        if (i == biggestElementIndex) 
            continue;

        cout << bst[i].data << ' ';
    }

    return 0;
}
