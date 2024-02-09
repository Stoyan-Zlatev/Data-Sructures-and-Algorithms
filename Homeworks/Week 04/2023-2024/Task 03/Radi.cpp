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

    if(position == 0)
    {
     SinglyLinkedListNode* newHead = new SinglyLinkedListNode(data);
     newHead->next = llist;
     return newHead;   
    }
    SinglyLinkedListNode* prev = llist;
    SinglyLinkedListNode* current = llist->next;
    size_t index = 1;
    while(index<position)
    {
        //move to the right
        prev = prev->next;
        current = current->next;
        index++;
    }
    SinglyLinkedListNode* toAdd = new SinglyLinkedListNode(data);
    prev->next = toAdd;
    toAdd->next = current;
    
return llist;
    
    
}