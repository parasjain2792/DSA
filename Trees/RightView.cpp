//link:https://leetcode.com/problems/binary-tree-right-side-view/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int > rightview;
    void helper(TreeNode* root,int level,int &maxlevel){
        if(root==NULL){
            return ;
        }
        if(level>maxlevel){
            rightview.push_back(root->val);
        }
        if(root->right){
            helper(root->right,level+1,maxlevel);
        }
        if(root->left){
            helper(root->left,level+1,maxlevel);
        }
        if(!root->right && !root->left){
            if(level>maxlevel){
                maxlevel=level;
            }
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        int maxlevel=0;
        if(root)
        rightview.push_back(root->val);
        helper(root,level,maxlevel);
        return rightview;
    }
};
