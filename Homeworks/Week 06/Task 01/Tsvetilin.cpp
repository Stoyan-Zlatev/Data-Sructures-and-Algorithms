#include <iostream>
#include <stack>

const size_t MAX_SIZE = 3e6 + 1;

struct Node
{
    long long value;

    long long left;
    long long right;
};

Node arr[MAX_SIZE];
size_t leftIndexes[MAX_SIZE]{};
size_t rigthIndexes[MAX_SIZE]{};
size_t center = 0;

void traverse(Node *root = arr, long long currentIndex = 0)
{

    if (currentIndex == 0)
        center += root->value;
    else if (currentIndex < 0)
        leftIndexes[-currentIndex - 1] += root->value;
    else if (currentIndex > 0)
        rigthIndexes[currentIndex - 1] += root->value;

    if (root->left != -1)
        traverse(arr + (root->left), currentIndex - 1);

    if (root->right != -1)
        traverse(arr + (root->right), currentIndex + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t j = 0; j < n; ++j)
    {
        std::cin >> arr[j].value >> arr[j].left >> arr[j].right;
    }

    traverse();

    size_t i = 0;
    std::stack<size_t> leftReversed;
    while (leftIndexes[i] != 0)
    {
        leftReversed.push(leftIndexes[i]);
        ++i;
    }

    while (!leftReversed.empty())
    {
        std::cout << leftReversed.top() << " ";
        leftReversed.pop();
    }

    std::cout << center << " ";

    i = 0;
    while (rigthIndexes[i] != 0)
    {
        std::cout << rigthIndexes[i] << " ";
        ++i;
    }

    return 0;
}
