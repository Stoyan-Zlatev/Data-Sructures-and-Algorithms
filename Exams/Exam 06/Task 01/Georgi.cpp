#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    size_t component = 0, index;
    std::vector<size_t> n; // neighbours
};

void dfs(std::vector<Node>& graph, std::vector<bool>& visited, size_t current, size_t component) {
    visited[current] = true;
    graph[current].component = component;
    
    for(size_t i = 0; i < graph[current].n.size(); i++) {
        if(!visited[graph[current].n[i]]) {
            dfs(graph, visited, graph[current].n[i], component);
        }
    }
}

int main() {
    size_t q;
    std::cin >> q;
    
    for(size_t i = 0; i < q; i++) {
        size_t verticesCount, edgesCount;
        std::cin >> verticesCount >> edgesCount;
        
        std::vector<Node> graph(verticesCount);
        for(size_t j = 0; j < edgesCount; j++) {
            size_t from, to;
            std::cin >> from >> to;
            
            graph[from].n.push_back(to);
            graph[from].index = from;
            
            
            graph[to].n.push_back(from);
            graph[to].index = to;
        } 
        
        std::vector<bool> visited(verticesCount, false);
        size_t component = 0;
        for(size_t j = 0; j < verticesCount; j++) {
            if(!visited[j]){
                dfs(graph, visited, j, component);
                component++;
            }
        }
        
        std::cout << component << " ";
    }
    
    return 0;
}