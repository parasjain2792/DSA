#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
int helper(int open,int close,bool check[],ll n,ll **dp){
    if(open>n || close>n){
        return 0;
    }
    if(open+close==(2*n)){
        return 1;
    }
    if(dp[open][close]!=-1){
        return dp[open][close];
    }
    
    if(open==close || check[open+close]){
        dp[open][close]=helper(open+1,close,check,n,dp);
    }
    else if(open==n){
        dp[open][close]=helper(open,close+1,check,n,dp);
    }
    else{
        dp[open][close]=(helper(open,close+1,check,n,dp)+helper(open+1,close,check,n,dp))%mod;
    }
    return dp[open][close];
}
int main(){   
    // write your code here
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        bool check[2*n+1]={0};
        ll **dp=new ll*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new ll[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<k;i++){
            int f;
            cin>>f;
            check[f-1]=1;
        }
        cout<<helper(0,0,check,n,dp)<<endl;
    }
    return 0;
}
