//link:https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
    #define ll long long
    bool wordBreak(string s, vector<string>& dict) {
        ll n=s.size();
        bool dp[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=0;
        }
        dp[0]=1;
        unordered_map<string,bool> umap;
        for(int i=0;i<dict.size();i++){
            umap[dict[i]]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                string s1=s.substr(j,(i-j));
                //cout<<s1<<endl;
                if(dp[j] && umap.count(s1)){
                    dp[i]=true;
                    break;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[n];
    }
};
