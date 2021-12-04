class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n+1][n+1];
        
        string rev=s;
        reverse(s.begin(),s.end());
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        int max_val=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};
