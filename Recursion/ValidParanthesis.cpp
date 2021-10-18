class Solution {
public:
    vector<string> ans;
    void helper(int open,int close,string s,int n){
        if(open+close==2*n){
            ans.push_back(s);
            return;
        }
        if(open==close){
             helper(open+1,close,s+"(",n);
            return;
        }
       else if(open==n){
           helper(open,close+1,s+")",n);
           return;
       }
        else{
            helper(open,close+1,s+")",n);
            helper(open+1,close,s+"(",n);
            return ;
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0;
        int close=0;
        helper(open,close,s,n);
        return ans;
    }
};
