#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

struct Person{
    long index, begin, end, chairIndex = -1;  
    
    // for the friends pq sort by earliest begin then by earliest end
    bool operator<(const Person& rhs) const {
        if(begin == rhs.begin) {
            return end > rhs.end;
        }
        return begin > rhs.begin;
    }
};

// for toLeave sort by earlies end
class Comparator {
public:
    bool operator() (const Person& lhs, const Person& rhs) {
        return lhs.end > rhs.end;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t friendsCount;
    std::cin >> friendsCount;
    
    std::priority_queue<Person> friends;
    for(size_t i = 0; i < friendsCount; i++) {
        long begin, end;
        std::cin >> begin >> end;
        friends.push({i, begin, end, -1});
    }
    
    long searched;
    std::cin >> searched;
    
    // min pq for the free chairs
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> freeChairs;
    for(size_t i = 0; i < friendsCount; i++) {
        freeChairs.push(i);
    }
    
    size_t result = 0;
    std::priority_queue<Person, std::vector<Person>, Comparator> toLeave;
    
    while(!friends.empty()) {
        auto current = friends.top();
        friends.pop();
        
        while(!toLeave.empty() && toLeave.top().end <= current.begin) {
            freeChairs.push(toLeave.top().chairIndex);
            toLeave.pop();
        }
        
        current.chairIndex = freeChairs.top();
        if(current.index == searched) {
            result = current.chairIndex;
            break;
        }
        
        freeChairs.pop();
        toLeave.push(current);
    }
    
    std::cout << result;
    
    return 0;
}