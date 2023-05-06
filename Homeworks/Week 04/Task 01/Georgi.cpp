SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position)
{
    if (position == 0) {
        SinglyLinkedListNode *temp = llist;
        llist = new SinglyLinkedListNode(data);
        llist->next = temp;
        return llist;
    }

    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *temp = llist;
    while (position > 0) {
        position--;
        prev = temp;
        temp = temp->next;
    }

    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->next = temp;
    prev->next = newNode;
    return llist;
}