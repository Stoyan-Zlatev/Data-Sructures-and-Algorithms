#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // TASK 01
    // SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    // TASK 02
    /*
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* ptr1 = llist1->head;
        SinglyLinkedListNode* ptr2 = llist2->head;

        for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
                ptr1 = ptr1->next;
            }
        }

        for (int i = 0; i < llist2_count; i++) {
            if (i != llist2_count-1) {
                ptr2 = ptr2->next;
            }
        }

        ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);
        fout << result;
    */


    // TASK 03
    // SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);
   
    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
