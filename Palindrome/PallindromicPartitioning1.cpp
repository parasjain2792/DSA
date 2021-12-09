//link:https://leetcode.com/problems/palindrome-partitioning/solution/
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> res;
        func(s,0,res);
        return ans;
    }
    void func(string s,int index,vector<string> res){
        if(index==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                res.push_back(s.substr(index,i-index+1));
                func(s,i+1,res);
                res.pop_back();
               // dp[index][i]=1;
            }
        }
        return ;
    }
    bool isPalindrome(string s,int start,int end){
        int i=start;
        int j=end;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
