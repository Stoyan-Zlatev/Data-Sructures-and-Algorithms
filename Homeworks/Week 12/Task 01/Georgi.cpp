#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class UnionFind {
private:
    std::vector<int> parentsContainer;

public:
    UnionFind(int vertexCount): parentsContainer(vertexCount) {
        for(int i = 0; i < vertexCount; i++) {
            parentsContainer[i] = i;
        }
    }
    
    bool areInOneSet(int first, int second) {
        return findParent(first) == findParent(second);
    }
    
    int findParent(int vertex) {
        if(parentsContainer[vertex] == vertex) {
            return vertex;
        }
        
        int result = findParent(parentsContainer[vertex]);
        parentsContainer[vertex] = result; 
        
        return result;
    }
    
    void unionVertices(int first, int second) {
        int parentOfFirst = findParent(first);
        int parentOfSecond = findParent(second);
        
        parentsContainer[parentOfFirst] = parentOfSecond;
    }
};


int main() {
    int vertextCount, edgesCount;
    std::cin >>vertextCount >> edgesCount;
    UnionFind graph(vertextCount);

    for(int i = 0; i < edgesCount; i++) {    
        int first, second;
        std::cin >> first >> second;
        graph.unionVertices(first - 1, second - 1);
    }
    
    int queriesCount;
    std::cin >> queriesCount;
    
    std::string result = "";
    
    for(int i = 0; i < queriesCount; i++) {
        int command, first, second;
        std::cin >> command >> first >> second;
        
        if(command == 1) {
            result += graph.areInOneSet(first - 1, second - 1) ? '1' : '0';
        } 
        else if(command == 2) {
            graph.unionVertices(first - 1, second - 1);
        }
    }
    
    std::cout << result;
    
    return 0;
}