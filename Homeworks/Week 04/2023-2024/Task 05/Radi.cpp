#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
   size_t data;
   Node*prev; 
   Node*next;  
};

struct List
{
private:
    Node*head=nullptr;
    Node*tail = nullptr;
    Node*mid = nullptr;

    size_t count = 0;
    
public:    
void moveToBack()
{
    if(count==1)
    {
        return;
    }
    
    if(count==2)
    {
     Node* swp = head;
     head = tail;
     tail = swp;
     head->prev = nullptr;
     head->next = tail;
     tail->prev = head;
     tail->next = nullptr;
     mid=head;
     return;
    }
    
   Node* newHead = mid->next;
   Node* newTail = mid;
   tail->next = head;
   head->prev = tail;
   newHead->prev = nullptr; 
   newTail->next = nullptr;
   mid = tail;
    if(count%2==1)
    {
        mid=mid->prev;
    }
   head = newHead;
   tail = newTail;
}

    void put(size_t newData)
    {   
        if(count==0)
        {
            head=new Node{newData,nullptr,nullptr};
            tail = head;
            mid=head;
            count++;
            return;
        }
        
        tail->next = new Node{newData,tail,nullptr};
        tail = tail->next;
        count++;
        if(count%2==0 && count!=2)
        {
            mid = mid->next;
        }
    }
    
    void eraseBack()
    {
        if(count==0)
        {
            return;
        }
        
        if(count==1)
        {
            head= nullptr;
            tail=nullptr;
            mid = nullptr;
            count = 0;
            return;
        }
        count--; 
        tail = tail->prev;
        tail->next = nullptr;
        if(count%2==1 && count!=1)
        {
           mid = mid->prev; 
        }
    }
    
    void print()const
    {
        cout<<count<<'\n';
        Node* iter = head;
        while(iter)
        {
           cout<<iter->data<<" ";
           iter = iter->next; 
        }
        cout<<'\n';
    }

};


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List data;
    size_t n;
    cin>>n;
    char cmd[20];
    size_t x;

    for(size_t i = 0; i < n; i++)
    {
        cin>>cmd;
        if(cmd[0]=='g')
        {
            data.eraseBack();
        }
        else if(cmd[0]=='a')
        {
            cin>>x;
            data.put(x);
        }
        else
        {
          data.moveToBack();
        }
    }
    data.print();
    return 0;
}
