#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll solve(ll n,ll k,int first,ll ***dp){
    if(n==1){
        if(k==0){
            return 1;
        }
        return 0;
    }
    if(k<0)
        return 0;
    
    if(dp[first][n][k]!=-1){
        return dp[first][n][k];
    }
    ll x=solve(n-1,k,0,dp);
    ll y=0;
    if(first==1){
        y= solve(n-1,k-1,1,dp);
    }
    else{
        y=solve(n-1,k,1,dp);
    }
    ll ans=(x+y)%mod;
    dp[first][n][k]=ans;
    return ans;
}
int main(){
    ll t;
    cin>>t;
     ll ***dp=new ll**[2];
        for(int i=0;i<2;i++){
            dp[i]=new ll*[101];
            for(int j=0;j<=100;j++){
                dp[i][j]=new ll[100+1];
                for(int l=0;l<=100;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
    while(t--){
        ll n,k;
        cin>>n>>k;
       
        int first=0;
        ll x=solve(n,k,0,dp);
        ll y=solve(n,k,1,dp);
        ll ans=(x+y)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
