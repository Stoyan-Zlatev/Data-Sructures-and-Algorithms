#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_set>

long long bfs(std::vector<std::vector<size_t>>& graph, std::unordered_set<size_t>& notToVisit, size_t from, size_t to) {
    std::queue<size_t> toProcess;
    std::vector<bool> visited(graph.size(), false);
    toProcess.push(from);
    
    long long pathLength = -1;
    size_t currentLevelLength = 0;
    while(!toProcess.empty()) {
        size_t levelLength = toProcess.size();
        while(levelLength > 0) {
            size_t current = toProcess.front();
            toProcess.pop();
            
            visited[current] = true;
            
            if(current == to) {
                pathLength = currentLevelLength;
                break;
            }
            
            for(auto& adj: graph[current]) {
                if(!visited[adj] && notToVisit.count(adj) == 0) {
                    toProcess.push(adj);
                }
            }
            
            levelLength--;
        }
        
        if(pathLength != -1) {
            break;
        }
        currentLevelLength++;
    }
    
    return pathLength;
}

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    
    std::vector<std::vector<size_t>> graph(verticesCount);
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    size_t toVisitCount;
    std::cin >> toVisitCount;
    std::unordered_set<size_t> notToVisit;
    std::vector<size_t> toVisit(toVisitCount);
    
    for(size_t i = 0; i < toVisitCount; i++) {
        std::cin >> toVisit[i];
        notToVisit.insert(toVisit[i]);
    }
    
    size_t notToVisitCount;
    std::cin >> notToVisitCount;
    
    for(size_t i = 0; i < notToVisitCount; i++) {
        size_t current;
        std::cin >> current;
        notToVisit.insert(current);
    }
    
    long long pathLength = 0;
    
    notToVisit.erase(toVisit[0]);
    for(size_t i = 1; i < toVisitCount; i++) {
        notToVisit.erase(toVisit[i]);
        pathLength += bfs(graph, notToVisit, toVisit[i - 1], toVisit[i]);
    }
    
    std::cout << pathLength;
    
    return 0;
}