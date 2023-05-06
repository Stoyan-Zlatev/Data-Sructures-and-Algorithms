#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      cout << fixed << setprecision(1);
      
    size_t length;
    std::cin >> length;
    priority_queue<double> leftSide;
    priority_queue<double, vector<double>, greater<double>> rightSide;
    double mid;
    std::cin >> mid;
    std::cout << mid << '\n';
    
    for(size_t i = 1; i < length; i++) {
        double current;
        std::cin >> current;
        
        if(leftSide.size() == 0 && rightSide.size() == 0) {
            if(mid < current){
                leftSide.push(mid);
                rightSide.push(current);
            } else {
                leftSide.push(current);
                rightSide.push(mid);
            }
            
            mid = (mid + current) / 2.0;
        }
        else {
            if (current > mid){
                if(leftSide.size() == rightSide.size()) {
                    rightSide.push(current);
                    mid = rightSide.top();
                } 
                else if(leftSide.size() < rightSide.size()){
                    double toMove = rightSide.top();
                    rightSide.pop();
                    leftSide.push(toMove);
                    rightSide.push(current);
                    mid = (rightSide.top() + leftSide.top()) / 2;
                } 
                else{
                    rightSide.push(current);
                    mid = (rightSide.top() + leftSide.top()) / 2;
                }
            } 
            else if (current < mid){
                if(leftSide.size() == rightSide.size()) {
                    leftSide.push(current);
                    mid = leftSide.top();
                } 
                else if(leftSide.size() < rightSide.size()){
                    leftSide.push(current);
                    mid = (rightSide.top() + leftSide.top()) / 2;
                } 
                else{
                    double toMove = leftSide.top();
                    leftSide.pop();
                    rightSide.push(toMove);
                    leftSide.push(current);
                    mid = (rightSide.top() + leftSide.top()) / 2;
                }
            } else {
                if(leftSide.size() < rightSide.size()){
                    leftSide.push(current);
                } 
                else {
                    rightSide.push(current);
                }
                
                mid = current;
            }
        }
        
        std::cout << mid << '\n';
    }
    
    return 0;
}