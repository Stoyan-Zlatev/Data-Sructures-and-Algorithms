// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    int len1 = 0;
    int len2 = 0;
    
    SinglyLinkedListNode* list1 = head1;
    SinglyLinkedListNode* list2 = head2;
    
    while(list1){
        ++len1;
        list1=list1->next;
    }
    
    
    while(list2){
        ++len2;
        list2=list2->next;
    }
    
    list1 = head1;
    list2 = head2;
    
    if(len1>len2){
        while(len1>len2){
            list1=list1->next;
            --len1;
        }
    }
    else if( len2>len1){
         while(len2>len1){
            list2=list2->next;
            --len2;
        }
}
    
    while(list1!=list2){
                    list1=list1->next;

                    list2=list2->next;

    }
    
    return list1->data;
    
}