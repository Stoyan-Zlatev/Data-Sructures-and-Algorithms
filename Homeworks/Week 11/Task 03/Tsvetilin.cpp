#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

typedef long long llong;
typedef std::pair<size_t, size_t> lpair;

const size_t MAX_SIZE = 5e5 + 20;
const size_t MOD = 1e9+7;

size_t distances[MAX_SIZE];
size_t paths[MAX_SIZE]{};

std::vector<lpair> adjacencyList[MAX_SIZE];

struct Comparator{
    bool operator()(const lpair& first, const lpair& second ) const {
        return first.first > second.first;
    }
};

void dijkstra(size_t V, size_t s)
{
        for (size_t i = 0; i < V; i++) 
            distances[i] = LLONG_MAX;
       
        distances[s] = 0;
        paths[s] = 1;
 
        std::priority_queue<lpair, std::vector<lpair>, Comparator> pq;
        pq.push({ 0,s });
 
        while (!pq.empty())
        {
            size_t current = pq.top().second;
            size_t costToCurrent = pq.top().first;
            pq.pop();
 
            if(costToCurrent > distances[current]) 
                continue;
 
            for (auto& neighbour : adjacencyList[current])
            {
                size_t child = neighbour.first;
                size_t newCost = costToCurrent + neighbour.second;
       
                if (distances[child] > newCost )
                {
                    distances[child] = newCost;
                    pq.push({newCost, child});
                }
                
                if (distances[child] > distances[current]) {
                    paths[child] += paths[current];
                    paths[child] %= MOD;
                }
                       
            }
        }
}

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t V,E,s,e;
    std::cin>>V>>E>>s>>e;

    size_t x,y,z;
    for(size_t i = 0; i < E; i++){
        std::cin>>x>>y>>z;
        adjacencyList[x].push_back({y,z});
        adjacencyList[y].push_back({x,z});
    }
    
    dijkstra(V,e);
    
    std::cout<<paths[s];
    
    return 0;
}
