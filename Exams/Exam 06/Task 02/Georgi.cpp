#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
  size_t to, weight;  
};

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    
    std::vector<std::vector<Edge>> graph(verticesCount);
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to, weight;
        std::cin >> from >> to >> weight;
        
        graph[from].push_back({ to, weight });
        graph[to].push_back({ from, weight });
    }
    
    size_t n;
    std::cin >> n;
    std::vector<size_t> path(n);
    for(size_t i = 0; i < n; i++) {
        std::cin >> path[i];
    }
    
    size_t weight = 0;
    bool exists = true;
    for(size_t i = 0; i < path.size() - 1; i++) {
        size_t current = path[i];
        size_t next = path[i + 1];
        
        bool found = false;
        for(size_t j = 0; j < graph[current].size(); j++) {
            if(graph[current][j].to == next) {
                found = true;
                weight += graph[current][j].weight;
                break;
            }
        }
        
        if(!found) {
            exists = false;
            break;
        }
    }
    
    // hackerrank dies on ternary
    if(!exists) {
        std::cout << -1;
    } else {
        std::cout << weight;
    }
    
    return 0;
}