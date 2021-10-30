#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> mat,int n,int m){
    vector<int> dp(n,0);
    int index[n][m]={0};
    for(int i=0;i<m;i++){
        index[0][i]=0;
        for(int j=1;j<n;j++){
            if(mat[j][i]>=mat[j-1][i]){
                index[j][i]=index[j-1][i];
            }
            else{
                index[j][i]=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        dp[i]=i;
        for(int j=0;j<m;j++){
            dp[i]=min(index[i][j],dp[i]);
        }
    }
    return dp;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        vector<int> dp=solve(arr,n,m);
        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            if(dp[r]<=l){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
