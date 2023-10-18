#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int value, Node* next = nullptr, Node* prev = nullptr) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    size_t length = 0;
public:
    LinkedList() {
        head = tail = nullptr;
    }

    size_t getLength() {
        return length;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        ++length;
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            head = tail = nullptr;
            delete tail;
            --length;
            return;
        }

        Node* prev = tail->prev;

        prev->next = nullptr;
        delete tail;
        tail = prev;

        --length;
    }

    void pop_front() {
        if (head == nullptr)
            return;

        --length;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* next = head->next;
        delete head;
        head = next;
        head->prev = nullptr;
        if (next == tail) {
            tail = head;
        }
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    void remove(Node* toRemove) {
        if (head == toRemove) {
            this->pop_front();
            return;
        }

        --length;

        toRemove->prev->next = toRemove->next;
        if (toRemove == tail) {
            tail = toRemove->prev;
        }
        else {
            toRemove->next->prev = toRemove->prev;
        }
        delete toRemove;
    }
};

Node* nodeContainer[2000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LinkedList l;
    int queries, maxCapacity;

    std::cin >> queries >> maxCapacity;

    for (int i = 0; i < queries; i++) {
        int package;
        std::cin >> package;

        size_t length = l.getLength();
        Node* existingNode = nodeContainer[package - 1];

        if (existingNode != nullptr) {
            // swap front and existing node;
            l.remove(existingNode);
            l.push_front(package);
            std::cout << "true" << "\n";
            continue;
        }

        if (length == maxCapacity) {
            Node* tail = l.getTail();
            nodeContainer[tail->value - 1] = nullptr;
            l.pop_back();
        }

        l.push_front(package);
        nodeContainer[package - 1] = l.getHead();
        std::cout << "false" << "\n";
    }

    return 0;
}