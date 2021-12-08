//link:https://leetcode.com/problems/count-different-palindromic-subsequences/submissions/
class Solution {
public:
    int mod=1e9+7;
    int solution(string s){
        int n=s.size();
        unordered_map<char,int> umap;
        int dp[n][n]; 
        int next[n];
        int prev[n];
        for(int i=0;i<n;i++){
           if(umap.count(s[i])==0){
               prev[i]=-1;
           }
            else{
                prev[i]=umap[s[i]];
            }
            umap[s[i]]=i;
        }
        umap.clear();
        for(int i=n-1;i>=0;i--){
              if(umap.count(s[i])==0){
               next[i]=-1;
           }
            else{
                next[i]=umap[s[i]];
            }
            umap[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        for(int gap=2;gap<=n;gap++){
            for(int i=0,j=gap-1;j<n;i++,j++){
                if(gap==2){
                    dp[i][j]=2;
                }
                else if(s[i]!=s[j]){
                    dp[i][j]=(((dp[i+1][j]+dp[i][j-1])%mod)-dp[i+1][j-1]+mod)%mod;
                }
                else{
                    if(next[i]==j && i==prev[j]){
                        dp[i][j]=((2*dp[i+1][j-1])%mod+2)%mod;
                    }
                    else if(next[i]==prev[j]){
                        dp[i][j]=((2*dp[i+1][j-1])%mod+1)%mod;
                    }
                    else{
                        dp[i][j]=(((2*dp[i+1][j-1])%mod)-dp[next[i]+1][prev[j]-1]+mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    int countPalindromicSubsequences(string s) {
        return solution(s);
    }
};
