#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const size_t MAX_SIZE = 1e6 + 1;
vector<size_t> tree[MAX_SIZE];
deque<size_t> employees;

void sumEmployees(size_t root, size_t *sums) {
    root = employees.front();
    for (auto x: tree[root]) {
        for (auto y: employees) {
            sums[y]++;
        }
        employees.push_front(x);
        sumEmployees(x, sums);
    }
    employees.pop_front();
}

int main() {
    size_t N, x, y;
    cin >> N;
    size_t ribs = N - 1;
    size_t sums[N];
    for (size_t i = 0; i < ribs; i++) {
        cin >> x >> y;
        tree[x].push_back(y);
        sums[i] = 0;
    }
    sums[N-1]=0;

    employees.push_back(0);
    sumEmployees(0, sums);
    for (int i = 0; i < N; ++i) {
        cout << sums[i] << " ";
    }

    return 0;
}
