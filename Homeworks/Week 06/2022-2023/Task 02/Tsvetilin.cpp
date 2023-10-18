#include <iostream>
#include <climits>

const size_t MAX_SIZE = 3e6 + 1;

struct Node
{
    long long value;

    long long left;
    long long right;
};

Node arr[MAX_SIZE];

bool isValidTree(Node *root, long long min = 1, long long max = LLONG_MAX)
{

    return (min <= root->value && root->value <= max) &&
           (root->left == -1 || isValidTree(arr + (root->left), min, root->value - 1)) &&
           (root->right == -1 || isValidTree(arr + (root->right), root->value + 1, max));
}

int main()
{
    size_t t;
    std::cin >> t;

    for (size_t i = 0; i < t; ++i)
    {
        size_t n;
        std::cin >> n;

        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> arr[j].value >> arr[j].left >> arr[j].right;
        }

        std::cout << isValidTree(arr) << '\n';
    }
    
    return 0;
}