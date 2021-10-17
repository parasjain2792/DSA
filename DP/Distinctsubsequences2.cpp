// link:https://leetcode.com/problems/distinct-subsequences-ii/
class Solution {
public:
    #define ll long long
    int distinctSubseqII(string s) {
        ll n=s.size();
        ll dp[n+1];
        ll last[27];
        for(int i=0;i<=26;i++){
            last[i]=-1;
        }
        dp[0]=1;
        ll mod=1e9+7;
        for(int i=0;i<n;i++){
            int index=s[i]-'a';
            dp[i+1]=(2*dp[i])%mod;
            if(last[index]>=0)
                dp[i+1]-=dp[last[index]];
                dp[i+1]%=mod;
                last[index]=i;
        }
        dp[n]--;
        if(dp[n]<0) dp[n]+=mod;
        
        return dp[n];
    }
};
