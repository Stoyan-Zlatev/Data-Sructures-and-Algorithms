#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long powers1[100000];
long long powers2[100000];

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 1;
const int PRIME_NUMBER1 = 997;
const int PRIME_NUMBER2 = 31;

void calculatePowers() {
    long long current = 1;
    for (int i = 0; i < 100000; i++) {
        powers1[i] = current;
        current = (current * PRIME_NUMBER1) % MOD1;
    }

    current = 1;
    for (int i = 0; i < 100000; i++) {
        powers2[i] = current;
        current = (current * PRIME_NUMBER2) % MOD2;
    }
}

// k * 26 ^ n-1 + k * 26 ^ n- 2.... 
long long rollingHash(long long prevHash, long long length, char removed, char added, long long powers[], int mod, int primeNumber) {
    prevHash = (prevHash - (removed - 'a' + 1) * powers[length - 1]) % mod;
    if (prevHash < 0)
        prevHash += mod;

    return (prevHash * primeNumber + (added - 'a' + 1)) % mod;
}

long long hashFunc(const string& str, long long length, long long powers[], int mod) {
    long long hashResult = 0;

    for (long long i = 0; i < length; i++) {
        hashResult += (str[i] - 'a' + 1) * powers[length - 1 - i];
        hashResult %= mod;
    }

    return hashResult;
}

// 012345
// banana
// nananabatman

bool hasSubStr(const string& s1, const string& s2, size_t length) {
    unordered_set<long long> container1, container2;

    long long currentHash1 = hashFunc(s1, length, powers1, MOD1);
    long long currentHash2 = hashFunc(s1, length, powers2, MOD2);
    container1.insert(currentHash1);
    container2.insert(currentHash2);
    for (long long j = 0; j < s1.size() - length; j++) {
        currentHash1 = rollingHash(currentHash1, length, s1[j], s1[length + j], powers1, MOD1, PRIME_NUMBER1);
        container1.insert(currentHash1);

        currentHash2 = rollingHash(currentHash2, length, s1[j], s1[length + j], powers2, MOD2, PRIME_NUMBER2);
        container2.insert(currentHash2);
    }

    long long currentS2Hash1 = hashFunc(s2, length, powers1, MOD1);
    long long currentS2Hash2 = hashFunc(s2, length, powers2, MOD2);
    if (container1.count(currentS2Hash1) > 0 && container2.count(currentS2Hash2) > 0) {
        return true;
    }

    for (long long j = 0; j < s2.size() - length; j++) {
        currentS2Hash1 = rollingHash(currentS2Hash1, length, s2[j], s2[length + j], powers1, MOD1, PRIME_NUMBER1);
        currentS2Hash2 = rollingHash(currentS2Hash2, length, s2[j], s2[length + j], powers2, MOD2, PRIME_NUMBER2);
        if (container1.count(currentS2Hash1) > 0 && container2.count(currentS2Hash2) > 0) {
            return true;
        }
    }

    return false;
}

int main() {
    calculatePowers();
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() < s2.size()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    // if we have solution with length 5 => we have solution with length 4
    long long left = 0, right = s2.size(), result = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (hasSubStr(s1, s2, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    std::cout << result;

    return 0;
}