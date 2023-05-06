#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

// 75/100
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t itemsCount;
    std::cin >> itemsCount;
    
    std::unordered_map<size_t, std::set<size_t>> boughtItemsTimes;
    // map - key => time, value => map with each item how many times has been bought till now
    std::map<size_t, std::unordered_map<size_t, size_t>> boughtAt;
    for(size_t i = 0; i < itemsCount; i++) {
        size_t item, time;
        std::cin >> item >> time;
        boughtItemsTimes[item].insert(time);
        boughtAt[time][item]++;
    }
    
    // as in dp - update the information of i + 1 with the information from i
    for(auto iter = boughtAt.begin(), prev = boughtAt.begin(); iter != boughtAt.end(); ++iter) {
        if(iter == boughtAt.begin()) {
            continue;    
        }
        
        // TODO: ABORT ERROR - 75/100
        for(auto& kvp: (*prev).second) {
            (*iter).second[kvp.first] += kvp.second;
        }
        prev = iter;
    }
    
    size_t timesCount;
    std::cin >> timesCount;
    
    for(size_t i = 0; i < timesCount; i++) {
        long long current;
        std::cin >> current;
        
        auto lower = boughtAt.upper_bound(current);
        --lower;
        if(lower == boughtAt.end()) {
            std::cout << -1 << '\n';
            continue;
        }
        
        size_t maxElement = 0;
        size_t maxSize = 0;
        for(auto& kvp: (*lower).second) {
            if(kvp.second > maxSize) {
                maxElement = kvp.first;
                maxSize = kvp.second;
            }
            else if(kvp.second == maxSize) {
                auto maxElementLastSeen = boughtItemsTimes[maxElement].upper_bound(current);
                auto currentLastSeen = boughtItemsTimes[kvp.first].upper_bound(current);
                --maxElementLastSeen;
                --currentLastSeen;
                if(*maxElementLastSeen < *currentLastSeen) {
                    maxElement = kvp.first;
                    maxSize = kvp.second;
                }
            }
        }
        
        std::cout << maxElement << '\n';
    }
    
    return 0;
}