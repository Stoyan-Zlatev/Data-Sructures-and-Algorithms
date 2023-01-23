#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void removeComplex(int devidedBy){
        //  TODO: write your code here
        while (head && head->data % devidedBy == 0) {
            head = head->next;
        }

        auto prev = head;
        for (auto i = head; i; i = i->next) {
            if (i->data % devidedBy == 0) {
                while (i->next && (i->next->data % devidedBy == 0)) {
                    i = i->next;
                }
                prev->next = i->next;
            }
            prev = i;
        }

    } // end removeComplex
private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}
