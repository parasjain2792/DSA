//find whether a subset is there or not with sum k in an array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        int arr[n]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k;
        int dp[2][k+1]={0};
        for(int i=0;i<2;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        dp[1][0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                if(j>=arr[i] && !dp[(i+1)%2][j])
                {
                    dp[i%2][j]=dp[(i+1)%2][j-arr[i]];
                }
                else{
                    dp[i%2][j]=dp[(i+1)%2][j];
                }
            }
        }
        if(dp[(n-1)%2][k])
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
