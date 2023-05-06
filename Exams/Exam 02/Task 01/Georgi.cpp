void SinglyLinkedList::replace(int X)
{
    Node* prev = nullptr;
    Node* iter = head;
    
    while(iter){
        if(iter->value == X){
            if(iter == head){
                size += (X - 1);
                head = new Node(1, head);
                iter = head;
                for(int i = 0; i < X - 1; i++){
                    iter->next = new Node(1, iter->next);
                    iter = iter->next;
                }
                
                iter->next = iter->next->next;
                if(!iter->next){
                    tail = iter;
                }
                
            } else if(iter == tail){
                size += (X - 1);
                iter = tail;
                iter->value = 1;
                for(int i = 0; i < X - 1; i++){
                    iter->next = new Node(1, nullptr);
                    iter = iter->next;
                }
                tail = iter;
                break;
            } else {
                size += (X - 1);
                iter->value = 1;
                for(int i =0;i<X - 1;i++){
                    iter->next = new Node(1, iter->next);
                    iter = iter->next;
                }
            }
        }
        
        iter = iter->next;
    }
    
}