//link:https://classroom.codingninjas.com/app/classroom/me/7991/content/120996/offering/1412289/problem/7700
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int dp[n+1]={0};
        int limit=floor(sqrt(n));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+1;
        }
        for(int i=2;i<=limit;i++){
            int val=pow(i,2);
            for(int j=val;j<=n;j++){
                if(j!=val)
                dp[j]=min(dp[j-val]+1,dp[j]);
                else{
                    dp[j]=1;
                }
            }
        }    
        cout<<dp[n]<<endl;
    }
    return 0;
}
