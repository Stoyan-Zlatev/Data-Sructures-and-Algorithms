#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void dfs(std::vector<std::vector<size_t>>& graph, std::vector<bool>& visited, size_t componentIndex, size_t current, std::vector<size_t>& counter) {
    visited[current] = true;
    counter[componentIndex]++;
    
    for(auto& adj: graph[current]) {
        if(!visited[adj]) {
            dfs(graph, visited, componentIndex, adj, counter);
        }
    }
}

int main() {
    size_t verticesCount, edgesCount, del;
    std::cin >> verticesCount >> edgesCount >> del;
    std::vector<std::vector<size_t>> graph(verticesCount);
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    std::vector<bool> visited(verticesCount);
    
    size_t componentIndex = 0;
    std::vector<size_t> counter(verticesCount);
    for(size_t i = 0; i < verticesCount; i++) {
        if(!visited[i]) {
            dfs(graph, visited, componentIndex, i, counter);
            componentIndex++;
        }
    }
    
    size_t result = 0;
    for(size_t i = 0; i < counter.size(); i++) {
        if(counter[i] != 0 && counter[i] % del == 0) {
            result++;
        }
    } 
    
    std::cout << result;
    
    return 0;
}