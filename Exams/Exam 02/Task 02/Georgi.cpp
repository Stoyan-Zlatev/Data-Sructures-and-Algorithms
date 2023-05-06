void SinglyLinkedList::replace(int X)
{
    Node* iter = head;
    int index = 0;
    
    while(index < X && iter != nullptr){
        index++;
        iter = iter->next;
    }
    if(iter == nullptr)
        return;
    
    int value = iter->value;
    iter = head;
    while(iter != nullptr){
        if(iter->value == value)
        {
               if(iter->next){
                   iter->value = iter->next->value;
               } else {
                   break;
               }
        }
        
        iter = iter->next;
    }
}