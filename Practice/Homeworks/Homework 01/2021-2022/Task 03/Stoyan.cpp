#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cin >> word;

    size_t symbolsCount;
    cin >> symbolsCount;

    char searchedSymbol;
    cin >> searchedSymbol;

    //Find how many times the symbol is present
    //in Maria's word
    size_t counter = 0;
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] == searchedSymbol){
            counter ++;
        }
    }

    //Multiply the times we found the symbol with the times
    //Maria will write the whole word
    counter *= symbolsCount / word.size();

    //Check the remainder of the word only if Maria has
    //to write less than the whole word or if we are sure
    //that the symbol is present at least once in the word
    if (symbolsCount < word.size() or counter != 0) {
        //Add the times we find the symbol in the remainder of
        //the word
        size_t remainder = symbolsCount % word.size();
        for (int i = 0; i < remainder; ++i) {
            if (word[i] == searchedSymbol) {
                counter++;
            }
        }
    }

    cout << counter;
    return 0;
}
