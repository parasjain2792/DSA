//link:https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* headE=NULL;
        Node* tailE=NULL;
        Node* heado=NULL;
        Node* tailo=NULL;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data%2==0){
                if(headE==NULL){
                    headE=temp;
                    tailE=temp;
                }
                else{
                    tailE->next=temp;
                    tailE=tailE->next;
                }
            }
            else {
                if(heado==NULL){
                    heado=temp;
                    tailo=temp;
                }
                else{
                    tailo->next=temp;
                    tailo=tailo->next;
                }
            }
            temp=temp->next;
        }
        //cout<<heado->data;
        if(headE==NULL){
            return heado;
        }
        else{
            tailE->next=heado;
            if(tailo)
            tailo->next=NULL;
            return headE;
            
        }
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
