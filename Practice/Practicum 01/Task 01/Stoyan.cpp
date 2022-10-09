#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string password;
    cin >> password;

    string encryptedPassword = "";

    if (password.size() > 0) {
        char currentSymbol = password[0];
        size_t symbolCounter = 0;

        for (char symbol: password) {
            if (currentSymbol != symbol) {
                encryptedPassword += to_string(symbolCounter);
                encryptedPassword += currentSymbol;
                currentSymbol = symbol;
                symbolCounter = 1;
            } else {
                symbolCounter++;
            }
        }
        
        encryptedPassword += to_string(symbolCounter);
        encryptedPassword += currentSymbol;
    }

    cout << encryptedPassword;
    return 0;
}
