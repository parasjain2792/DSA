//link:https://leetcode.com/problems/shortest-common-supersequence/submissions/
class Solution {
public:
    #define ll long long
    string shortestCommonSupersequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        ll **dp=new ll *[m+1];

        for(ll i=0;i<=m;i++){
            dp[i]=new ll[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=m;
        int j=n;
        string ans="";
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans=ans+t[j-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                ans=ans+s[i-1];
                i--;
            }
            else{
                ans=ans+t[j-1];
                j--;
            }
        }
        while(i>0){
            ans.push_back(s[i-1]);
		     i--;
         }
         while(j>0){
             ans.push_back(t[j-1]);
            j--;
         }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
