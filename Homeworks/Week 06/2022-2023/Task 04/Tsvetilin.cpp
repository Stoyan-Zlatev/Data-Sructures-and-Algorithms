#include <vector>
#include <iostream>
#include <string>

const size_t LETTERS_COUNT = 26;
const int LETTER_TO_INDEX = -'a';

struct Node
{
    char value = 0;
    bool isEnd = false;
    Node *children[LETTERS_COUNT]{};

    Node(char value) : value(value) {}
};

Node *tree = new Node(0);

int main()
{
    size_t n;
    std::cin >> n;

    std::string word;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> word;
        Node *current = tree;

        for (size_t j = 0; j < word.length(); ++j)
        {
            if (current->children[word[j] + LETTER_TO_INDEX] == nullptr)
                current->children[word[j] + LETTER_TO_INDEX] = new Node(word[j]);

            current = current->children[word[j] + LETTER_TO_INDEX];
        }

        current->isEnd = true;
    }

    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> word;
        Node *current = tree;

        for (size_t j = 0; j < word.length(); ++j)
        {
            if (current->children[word[j] + LETTER_TO_INDEX] == nullptr)
                break;

            current = current->children[word[j] + LETTER_TO_INDEX];
        }

        if (current && current->isEnd)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}
