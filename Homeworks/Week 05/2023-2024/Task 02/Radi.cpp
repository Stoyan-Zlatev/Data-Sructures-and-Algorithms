#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

size_t arr[(size_t)1e6+5];

int main() {
    size_t N;   
    cin>>N;
    
    stack<size_t> minLeftIndex;
    size_t maxArea = 0;
    arr[0]=0;    
    for(size_t i = 1; i < N+1; i++)
    {
        cin>>arr[i];     
    }
    
    
    arr[N+1] = 0;
    minLeftIndex.push(0);
    
    for(size_t i = 1; i <= N + 1; i++)
    {
        //search incresing order starting from the currentLeftMostIndex(top of stack) to the rightMostIndex
        if(arr[i] > arr[minLeftIndex.top()])
        {
            minLeftIndex.push(i);
            continue;
        }
        
        //arr[i]->rightMostIndex
        //each minLeftIndex.top() ->currentLeftMostIndex
        //search max width starting from rightMostIndex to currentLeftMostIndex
        while(arr[i]<=arr[minLeftIndex.top()])
        {
            if(minLeftIndex.size()==1)
            {
                break;
            }
            //take the height that is on index on top of the stack
            //after this index all values are bigger until rightMostIndex
            //so it is possible to find an area in this range
            size_t currentMaxHeight = arr[minLeftIndex.top()];
            
            //find where will be the left boundary
            while(arr[minLeftIndex.top()] == currentMaxHeight)
            {
                minLeftIndex.pop();
            }
            
            int rightIndex = i;
            int leftIndex = minLeftIndex.top();
            maxArea = max(maxArea, (rightIndex-leftIndex-1)*currentMaxHeight);
        }
        
        minLeftIndex.push(i);     
    }
    cout<<maxArea;
    return 0;
}
