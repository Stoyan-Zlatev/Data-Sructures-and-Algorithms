SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(position == 0) {
        SinglyLinkedListNode* temp = llist->next;
        delete llist;
        return temp;
    }
    
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist;
    while(position != 0){
        position--;
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    delete current;
    
    return llist;
}