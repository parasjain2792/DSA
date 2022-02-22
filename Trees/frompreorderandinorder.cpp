// https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left
  Node* right;
};
*/
class Solution{
    public:
    int preindex=0;
    Node* helper(int in[],int pre[],int instart,int inend,int n){
        if(instart>inend){
            return NULL;
        }
        Node* root=new Node(pre[preindex++]);
        if(instart==inend)
        return root;
        int index;
        for(int i=0;i<n;i++){
            if(in[i]==root->data){
                index=i;
                break;
            }
        }
        root->left=helper(in,pre,instart,index-1,n);
        root->right=helper(in,pre,index+1,inend,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int instart=0;
        int inend=n-1;
        return helper(in,pre,instart,inend,n);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
