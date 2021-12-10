//link:https://leetcode.com/problems/palindrome-partitioning-ii/submissions/
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        int dp[n][n];
        for(int gap=1;gap<=n;gap++){
            for(int i=0,j=gap-1;j<n;i++,j++){
                if(gap==1){
                    dp[i][j]=1;
                }
                else  if(gap==2){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        int dp2[n];
        dp2[0]=0;
        for(int i=1;i<n;i++){
            int local=INT_MAX;
            for(int k=i;k>=0;k--){
                if(dp[k][i] && k!=0){
                    local=min(local,dp2[k-1]+1);
                }
                else if(dp[k][i] && k==0){
                    local=0;
                }
            }
            dp2[i]=local;
        }
        return dp2[n-1];
    }
};
