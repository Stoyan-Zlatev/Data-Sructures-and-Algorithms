#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void print() {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void solve(LinkedList &num2) {
        Node *curr1 = this->head;
        Node *curr2 = num2.head;

        stack <size_t> result;

        size_t remainder = 0;
        while (curr1 && curr2) {
            size_t sum = curr1->data + curr2->data + remainder;
            size_t digit = sum % 10;
            remainder = sum / 10;
            result.push(digit);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        if (curr2) {
            while (curr2) {
                size_t sum = curr2->data + remainder;
                remainder = sum / 10;
                size_t digit = sum % 10;
                result.push(digit);
                curr2 = curr2->next;
            }
        } else {
            while (curr1) {
                size_t sum = curr1->data + remainder;
                remainder = sum / 10;
                size_t digit = sum % 10;
                result.push(digit);
                curr1 = curr1->next;
            }
        }

        if (remainder) {
            result.push(remainder);
        }
        while (!result.empty()) {
            cout << result.top();
            result.pop();
        }
        // TODO: Implement this function
        // Feel free to modify the template to your liking
    }

private:
    Node *head, *tail;
};

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    num1.solve(num2);
}