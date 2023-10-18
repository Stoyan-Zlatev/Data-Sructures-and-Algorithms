#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Bulletin {
    int number;
    int id;
    
    bool operator<(const Bulletin& other) {
        return number < other.number || (number == other.number && id < other.id);
    }
};

int main() {
    int N;
    cin >> N;
    
    Bulletin bulletins[N];
    Bulletin sortedBulletins[N];
    for (int i =0; i <N; i++) {
        cin >> bulletins[i].number;
        bulletins[i].id = i;
    }
    
    sort(bulletins, bulletins + N);
    
    for (int i =0; i <N; i++) {
        sortedBulletins[bulletins[i].id].id = i;
    }
    
    for (int i = 0; i < N;i++) {
        cout << sortedBulletins[i].id << " ";
    }
}
