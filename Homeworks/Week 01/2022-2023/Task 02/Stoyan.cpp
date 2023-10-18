#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t N;
    cin >> N;
    
    vector<size_t> prices;
    size_t price;
    size_t profit = 0;

    for (size_t i = 0; i < N; i++) {
        cin >> price;
        prices.push_back(price);
    }

    size_t lower, higher;
    for (size_t i = 0; i < N - 1; i++) {
        higher = 0;
        lower = 0;
        while ((i < N - 1) && !(prices[i] < prices[i + 1]))
        {
            i++;
        }

        lower = prices[i];
        while ((i < N - 1) && (prices[i] < prices[i + 1]))
        {
            i++;
        }

        higher = prices[i];
        profit += (higher - lower);
    }

    cout << profit;
    return 0;
}
