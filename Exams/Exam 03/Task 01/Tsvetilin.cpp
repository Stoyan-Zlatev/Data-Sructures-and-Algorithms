#include <iostream>
#include <list>

struct Node
{
    size_t value = 0;

    Node *left = nullptr;
    Node *right = nullptr;

    Node(size_t val) { this->value = val; }
};

struct Tree
{
    Node *root = nullptr;

    void add(size_t val, Node *node)
    {

        if (node == nullptr)
        {
            root = new Node(val);
            return;
        }

        if (val < node->value)
        {
            if (node->left == nullptr)
            {
                node->left = new Node(val);
                return;
            }

            add(val, node->left);
        }
        else if (val > node->value)
        {
            if (node->right == nullptr)
            {
                node->right = new Node(val);
                return;
            }

            add(val, node->right);
        }
    }

    void traverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left && node->right)
        {
            std::cout << node->value << " ";
        }

        traverse(node->left);
        traverse(node->right);
    }
};

int main()
{
    size_t t;
    std::cin >> t;

    for (size_t i = 0; i < t; ++i)
    {
        Tree tree;
        size_t n;
        std::cin >> n;

        size_t x;

        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> x;
            tree.add(x, tree.root);
        }

        tree.traverse(tree.root);
        std::cout << std::endl;
    }

    return 0;
}
