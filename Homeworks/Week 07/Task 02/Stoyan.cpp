#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t Q, N, number;
    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        cin >> N;
        map<size_t, size_t> sweetIndex;
        vector<size_t> allSweets;
        size_t maxSequenceCount = 0, start = 0;
        for (size_t j = 0; j < N; j++) {
            cin >> number;
            allSweets.push_back(number);
            if (!sweetIndex.count(number)) {
                sweetIndex.insert(pair<size_t, size_t>(number, j));
                if ((j - start + 1) > maxSequenceCount) {
                    maxSequenceCount = (j - start + 1);
                }
            } else {
                for (size_t k = start; k < sweetIndex[number]; ++k) {
                    sweetIndex.erase(allSweets[k]);
                }
                start = sweetIndex[number] + 1;
                sweetIndex[number] = j;
            }
        }
        cout << maxSequenceCount << "\n";
    }
    return 0;
}
