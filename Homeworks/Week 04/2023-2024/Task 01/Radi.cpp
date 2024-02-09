// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
  SinglyLinkedListNode* head=nullptr;
  SinglyLinkedListNode* prev;

  while(head1!=nullptr && head2!=nullptr)
  {
      
          SinglyLinkedListNode* current = new SinglyLinkedListNode(head1->data>=head2->data?head2->data: head1->data);
          if(head1->data>=head2->data)
          {
              head2 = head2->next;
          }else
          {
              head1 = head1->next;
          }
          if(head==nullptr)
          {
              head = current;
              prev = head;
          }else
          {
          prev->next = current;
              prev = prev->next;
          }
  }  
    
      while(head1!=nullptr)
  {
          SinglyLinkedListNode* current = new SinglyLinkedListNode(head1->data);
          prev->next = current;
                        prev = prev->next;
        head1 = head1->next;

  }  
    
      while(head2!=nullptr)
  {
    SinglyLinkedListNode* current = new SinglyLinkedListNode(head2->data);
    prev->next = current;
                        prev = prev->next;

    head2 = head2->next;
  }  
    prev->next = nullptr;
return head;
}