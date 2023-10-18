#include <iostream>

const size_t MAX_LEN = 1e6;

struct Node
{
    size_t value = 0;

    Node *left = nullptr;
    Node *right = nullptr;

    long long ind = 0;
    size_t height = 0;

    Node(size_t val, long long ind, size_t height)
    {
        this->value = val;
        this->ind = ind;
        this->height = height;
    }
};

struct Tree
{
    Node *root = nullptr;

    size_t positive[MAX_LEN]{};
    size_t negative[MAX_LEN]{};
    size_t positiveH[MAX_LEN]{};
    size_t negativeH[MAX_LEN]{};

    void add(size_t val)
    {
        add(val, root);
    }

    void add(size_t val, Node *node, long long ind = 0, size_t height = 0)
    {

        if (node == nullptr)
        {
            root = new Node(val, ind, height);
            return;
        }

        ++height;
        if (val < node->value)
        {
            --ind;
            if (node->left == nullptr)
            {
                node->left = new Node(val, ind, height);
                return;
            }

            add(val, node->left, ind, height);
        }
        else if (val > node->value)
        {
            ++ind;
            if (node->right == nullptr)
            {
                node->right = new Node(val, ind, height);
                return;
            }

            add(val, node->right, ind, height);
        }
    }

    void traverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->ind > 0 && (positiveH[node->ind] == 0 || positiveH[node->ind] > node->height))
        {
            positive[node->ind] = node->value;
            positiveH[node->ind] = node->height;
        }

        if (node->ind < 0 && (negativeH[-node->ind] == 0 || negativeH[-node->ind] > node->height))
        {
            negative[-node->ind] = node->value;
            negativeH[-node->ind] = node->height;
        }

        traverse(node->left);
        traverse(node->right);
    }

    void printTop()
    {
        traverse(root);

        long long j = 1;
        while (negative[j] != 0)
        {
            ++j;
        }

        --j;
        while (j > 0)
        {
            std::cout << negative[j] << " ";
            --j;
        }

        std::cout << root->value << " ";

        j = 1;
        while (positive[j] != 0)
        {
            std::cout << positive[j] << " ";
            ++j;
        }
        std::cout << std::endl;
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
            tree.add(x);
        }

        tree.printTop();
    }

    return 0;
}
