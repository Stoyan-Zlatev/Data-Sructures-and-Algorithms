#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Node {
    size_t value;
    long long left, right;
};

const size_t MAX_VALUE = 3e8;
bool isBinary = true;

void checkTree(size_t root, const Node *tree, size_t minValue = 1, size_t maxValue = MAX_VALUE) {
    size_t currentValue = tree[root].value;
    if (currentValue < minValue || currentValue > maxValue) {
        isBinary = false;
    }

    // Check left subtree
    if (tree[root].left != -1) {
        checkTree(tree[root].left, tree, minValue, currentValue - 1);
    }
    // Check right subtree
    if (tree[root].right != -1) {
        checkTree(tree[root].right, tree, currentValue + 1, maxValue);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short T;
    cin >> T;
    size_t N;
    for (size_t i = 0; i < T; ++i) {
        cin >> N;
        Node tree[N];
        for (size_t j = 0; j < N; ++j) {
            cin >> tree[j].value >> tree[j].left >> tree[j].right;
        }
        checkTree(0, tree);
        cout << isBinary << '\n';
        isBinary = true;
    }

    return 0;
}
