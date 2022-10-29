/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
        SinglyLinkedListNode* toAdd = new SinglyLinkedListNode(data);


    if(position==0){
        toAdd->next=llist;
        return toAdd;
    }
    
    int index = 0;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    
    while(index<position){
        previous = current;
        current = current->next;
        ++index;
    }
    
    previous->next=toAdd;
    toAdd->next=current;
    
    return llist;
}