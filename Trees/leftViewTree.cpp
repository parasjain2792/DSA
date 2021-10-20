void helper(Node* root,vector<int> &ans,int height,int &max_height){
 if(root==NULL){
     
     return ;
 }
 if(height>max_height){
 
 ans.push_back(root->data)    ;
     max_height=height;
 }
 
 
 
 
 helper(root->left,ans,height+1,max_height);
 
 helper(root->right,ans,height+1,max_height);
 
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   int level=0;
   helper(root,ans,1,level);
   
   
   return ans;
}
