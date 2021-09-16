    ListNode* reverseList(ListNode* head) {
  if(!head)
       return NULL ;
        
     ListNode* prev=NULL;
     ListNode* current=head; 
     ListNode* next=head->next;
     
      while(current){
          
        next=current->next;
        current->next=prev;
          prev=current;
         current=next;
      }  
        head=prev;
        
        
        
        
    return head;
    }
