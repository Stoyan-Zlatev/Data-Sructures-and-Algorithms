int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int counter1 = 0, counter2 = 0;
    SinglyLinkedListNode* temp1 = head1;
    while(temp1 != nullptr){
        temp1 = temp1->next;
        counter1++;
    }
    
    SinglyLinkedListNode* temp2 = head2;
    while(temp2 != nullptr){
        temp2 = temp2->next;
        counter2++;
    }

    int diff = counter1 - counter2;
    temp1 = head1;
    temp2 = head2;
    while(diff > 0) {
        temp1 = temp1->next;
        diff--;
    }
    while(diff < 0) {
        temp2 = temp2->next;
        diff++;
    }
    
    while(temp1 != nullptr && temp2 != nullptr && temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return temp1->data;
}