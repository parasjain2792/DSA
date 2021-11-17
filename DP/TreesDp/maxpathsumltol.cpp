// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int res=INT_MIN;
    int max_sum(Node*root)
    {
        if (root==NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right==NULL)
        {
           
            return root->data;
        }
        
        // return maximum sum of path from root to leaf in left subtree
        int ls=max_sum(root->left);
        // return maximum sum of path from root to leaf in right subtree
        int rs=max_sum(root->right);
        
        if (root->right && root->left)
        {  
          //update res
           res=max(res,ls+rs+root->data);
           
           return max(ls,rs)+root->data;
        }
     
        if (root->left==NULL)
        {
            
            return rs+root->data;
        }
        if (root->right==NULL)
        {
            
            return ls+root->data;
        }
        
       
        
    }
    
    int maxPathSum(Node* root)
    {
        int val=max_sum(root);
        
        //res remains INT MIN when
        // 1. root=NULL;
        // 2. only children are not pr root node is present, itsesent;
        // 3. only right subtree is present or only left subtree is present
        
        
        if (res==INT_MIN)
        {
            return val;
        }
        
        //return res when both left and right subtree is present
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
