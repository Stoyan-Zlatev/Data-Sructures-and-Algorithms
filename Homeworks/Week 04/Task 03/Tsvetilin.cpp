/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
        if(position==0){
            SinglyLinkedListNode* head = llist->next;
            delete llist;
            return head;
        }
    
        SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    
    int i = 0;
    
    while(i<position){
    previous = current;
        current = current->next;
        if(!current){
            return llist;
        }
        ++i;
    }
    
    if(!current){
        current= previous;
    }
    
    previous->next=current->next;
    
    if(current){
        delete current;
    }
    
    return llist;
}