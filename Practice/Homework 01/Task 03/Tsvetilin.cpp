#include <iostream>

int main()
{
    std::string word;
    size_t count;
    char search;

    std::cin >> word;
    std::cin >> count;
    std::cin >> search;

    size_t fullWordWrittenCount = count / word.length();
    size_t partialWordWrittenIndex = count % word.length();
    
    size_t totalMatchingLettersInWord = 0;
    size_t partialMatchingLettersInWord = 0;

    for (size_t i = 0; i < word.length(); ++i)
    {
        if (word[i] == search)
        {
            ++totalMatchingLettersInWord;
            if (i < partialWordWrittenIndex)
            {
                ++partialMatchingLettersInWord;
            }
        }
    }

    size_t result = fullWordWrittenCount * totalMatchingLettersInWord + partialMatchingLettersInWord;
    std::cout << result;
}