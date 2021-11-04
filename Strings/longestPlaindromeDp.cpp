//link:https://leetcode.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int max_val=1;
        int start=0;
        int end=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                       dp[i][j]=1;
                        if(max_val<2){
                         max_val=2;
                         start=i;
                            end=j;
                        }
                    }
                    else
                        dp[i][j]=0;
                    
                }
                else{
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1]==1){
                            dp[i][j]=1;
                            if(max_val<gap+1){
                                start=i;
                                end=j;
                                max_val=gap+1;
                            }
                        }
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        string res=s.substr(start,max_val);
        return res;
    }
};
