class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n=s.size();
        int dp[n][n];
        for(int i=0;i<s.size();i++){
            
            for(int j=0;j<s.size();j++){
               if(i==j)
               {
                 dp[i][j]=1;
                  continue ;
                }
            dp[i][j]=0;
            }
            
        }
       for(int size=2;size<=n;size++){
           
           for(int i=0;i<=n-size;i++){
             int j=i+size-1;
             dp[i][j]=(s[i]==s[j])?2+dp[i+1][j-1]:max(dp[i+1][j],dp[i][j-1]);  
               
           }
       }
        
        return dp[0][n-1];
        
    }
};
