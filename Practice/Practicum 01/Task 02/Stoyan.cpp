#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int M, N;
    cin >> M >> N;

    long long gradesSum = 0;
    int currentGrade;
    for (int i = 0; i < N; i++) {
        cin >> currentGrade;
        gradesSum += currentGrade;
    }

    cout << ((gradesSum >= M*N) ? "yes": "no");
    return 0;
}
