#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    vector<size_t> children;
    size_t timeIn = 0;
    size_t timeOut = 0;
};

const size_t MAX_SIZE = 1e6 + 1;
Node tree[MAX_SIZE];
size_t timeCounter = 1;

void preOrder(size_t root) {
    tree[root].timeIn = timeCounter++;

    for (auto x: tree[root].children) {
        preOrder(x);
    }

    tree[root].timeOut = timeCounter++;
}

bool isPredecessor(size_t currentTimeIn, size_t currentTimeOut, size_t predecessorTimeIn, size_t predecessorTimeOut) {
    return currentTimeIn > predecessorTimeIn && currentTimeOut < predecessorTimeOut;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N, parent, child;
    cin >> N;
    size_t ribs = N - 1;
    cin >> parent >> child;
    tree[parent].children.push_back(child);
    size_t root = parent;
    for (size_t i = 1; i < ribs; i++) {
        cin >> parent >> child;
        tree[parent].children.push_back(child);
    }

    preOrder(root);
    size_t Q, x, y;
    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> x >> y;
        if (isPredecessor(tree[y].timeIn, tree[y].timeOut, tree[x].timeIn, tree[x].timeOut)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
