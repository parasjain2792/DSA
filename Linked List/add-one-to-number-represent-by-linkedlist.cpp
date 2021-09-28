/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/

class Solution
{
    public:
    struct Node * reverse(struct Node * root)
    {
        Node * temp=root,*prev,*next;
        next=root;
        prev=NULL;
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        root=prev;
        return root;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node * temp=head;
        Node * prev=NULL;
        int sum=0;
        int carry=1;
        while(temp!=NULL)
        {
            sum=temp->data+carry;
            carry=sum>=10?1:0;
            sum=sum>=10?sum%10:sum;
            temp->data=sum;
            prev=temp;
            temp=temp->next;
            
        }
        if(carry==1)
        {
            prev->next=new Node(carry);
        }
        head=reverse(head);
        return head;
    }
};
