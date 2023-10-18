#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> heights;
    int currentHeight;
    int maxVolume = 0;
    for (int i = 0; i < N; i++) {
        cin >> currentHeight;
        heights.push_back(currentHeight);
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int currentVolume = (j - i) * min(heights[i], heights[j]);
            if (maxVolume < currentVolume){
                maxVolume = currentVolume;
            }
        }
    }

    cout << maxVolume;
    return 0;
}
