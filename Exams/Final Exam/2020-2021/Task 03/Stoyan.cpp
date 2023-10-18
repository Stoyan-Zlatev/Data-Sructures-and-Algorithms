#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head = nullptr;
    Node *tail = nullptr;

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


    void reverse(int from, int to) {
        // TODO: Reverse the elements of the sublist starting
        //       at postiton from and ending at posion to.
        Node *prev = nullptr;
        Node *current = head;
        for (int i = 0; i < from - 1 && current; ++i) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            return;
        }

        Node *prevNode = nullptr;
        Node *next = nullptr;
        Node *nextConnection = current;

        for (int i = 0; i <= to - from && current; ++i) {
            next = current->next;
            current->next = prevNode;
            prevNode = current;
            current = next;
        }

        if (!prev) {
            head = prevNode;
        } else {
            prev->next = prevNode;
        }
        if (current) {
            nextConnection->next = current;
        } else {
            tail = nextConnection;
        }
    }

    void print() {
        Node *temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node *curr = head;

        while (curr) {
            Node *prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}