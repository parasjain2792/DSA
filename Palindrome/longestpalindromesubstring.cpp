class Solution {
public:
    string longestPalindrome(string s) {
      
        int n=s.size();
         int dp[n][n];
        int start=0;
        int max_val=0;
        for(int gap=1;gap<=n;gap++){
            for(int i=0,j=gap-1;j<n;j++,i++){
                if(gap==1){
                    dp[i][j]=1;
                    if(max_val<gap){
                        max_val=gap;
                        start=i;
                    }
                }else if(gap==2){
                    dp[i][j]=(s[i]==s[j])?1:0;
                     if(max_val<gap && dp[i][j]){
                        max_val=gap;
                        start=i;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=1;
                          if(max_val<gap && dp[i][j]){
                        max_val=gap;
                        start=i;
                    }
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                
            }
        }
        return s.substr(start,max_val);
    }
};class Solution {
public:
    string longestPalindrome(string s) {
      
        int n=s.size();
         int dp[n][n];
        int start=0;
        int max_val=0;
        for(int gap=1;gap<=n;gap++){
            for(int i=0,j=gap-1;j<n;j++,i++){
                if(gap==1){
                    dp[i][j]=1;
                    if(max_val<gap){
                        max_val=gap;
                        start=i;
                    }
                }else if(gap==2){
                    dp[i][j]=(s[i]==s[j])?1:0;
                     if(max_val<gap && dp[i][j]){
                        max_val=gap;
                        start=i;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=1;
                          if(max_val<gap && dp[i][j]){
                        max_val=gap;
                        start=i;
                    }
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                
            }
        }
        return s.substr(start,max_val);
    }
};
