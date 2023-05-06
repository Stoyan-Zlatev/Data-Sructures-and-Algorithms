#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    priority_queue<int, vector<int>, greater<int> > pq;
    int taskToDoOnIteration, timeBetween, batches;
    std::cin >> taskToDoOnIteration >> timeBetween >> batches;
    int tasks;
    std::cin >> tasks;
    
    int batchesDone = 0;
    for(int i = 0; i < tasks; i++) {
        int currentTask;
        std::cin >> currentTask;
        pq.push(currentTask);
        
        if((i + 1) % timeBetween == 0) {
            for(int j = 0; j < taskToDoOnIteration; j++) {
                if(pq.empty()){
                    break;
                }
                std::cout << pq.top() << " ";
                pq.pop();
            }
            
            if(++batchesDone == batches){
                break;
            }
        }
    }
    
    while(batchesDone < batches && !pq.empty()){
        for(int j = 0; j < taskToDoOnIteration; j++) {
            if(pq.empty()){
                break;
            }
            std::cout << pq.top() << " ";
            pq.pop();
        }
        
        batchesDone++;
    }
    
    return 0;
}