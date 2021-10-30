#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll **arr=new ll*[n];
        for(int i=0;i<n;i++){
            arr[i]=new ll[m];
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        ll **dp=new ll*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new ll[m+2];
            for(int j=0;j<=m+1;j++){
                dp[i][j]=INT_MAX;
            }
        }
        for(int i=1;i<=m;i++){
            dp[n-1][i]=arr[n-1][i-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]))+arr[i][j-1];
            }
        }
        ll min_val=INT_MAX;
        for(int i=1;i<=m;i++){
            min_val=min(min_val,dp[0][i]);
        }
        cout<<min_val<<endl;
    }
    return 0;
}
