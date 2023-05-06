#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

size_t result = 0;

// Logic
// count the sum of the children with the current node
// if % 2 == 0 => the mini graph can be extracted from the big one
size_t dfs(vector<unordered_set<size_t>>& graph, unordered_set<size_t>& visited, size_t current){
    if(graph[current].size() == 0){
        return 1;
    } 
    
    visited.insert(current);
    
    size_t children = 1; // counting the current node with the children
    for(auto& val: graph[current]) {
        if(!visited.count(val)){
            children += dfs(graph, visited, val);
        }
    }
    
    // if the current node + children % 2 == 0
    // we can delete this mini graph
    // and return 0 to the parent which called the method
    if(children % 2 == 0) { 
        result++;
        return 0;
    }
    
    return children;
}

int main() {
    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;
    
    vector<unordered_set<size_t>> graph(nodesCount + 1);
    
    for(size_t i = 0; i < nodesCount; i++){
        size_t first, second;
        cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }
    
    unordered_set<size_t> visited;
    dfs(graph, visited, 1);
    
    std::cout << result - 1; // there is always one extra because ot the logic
    
    return 0;
}