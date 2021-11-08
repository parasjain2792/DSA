//link:https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node *reverse(Node* head){
        if(head->next==NULL){
            return head;
        }
        Node* root=reverse(head->next);
        Node* next_val=head->next;
        head->next=next_val->next;
        next_val->next=head;
        return root;
        
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
       head=reverse(head);
       Node* cur=head;
       int maxv=head->data;
       Node* prev=head;
       head=head->next; 
       while(head){
           if(head->data>=maxv){
               maxv=head->data;
               prev=head;
               head=head->next;
           }
           else{
               prev->next=head->next;
               head=head->next;
           }
       }
     
     return reverse(cur);  
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends
