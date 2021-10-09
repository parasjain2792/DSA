#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int,int> c[n];
        double fun[n]={0};
        double max_val=0;
        for(int i=0;i<n;i++){
            cin>>c[i].first>>c[i].second;
            cin>>fun[i];
        }
        double dp[n]={0};
        dp[0]=fun[0];
        for(int i=1;i<n;i++){
            dp[i]=fun[i]-sqrt(pow(c[i].first-c[0].first,2)+(pow(c[i].second-c[0].second,2)));
            for(int j=i-1;j>=0;j--){
                double distance1=sqrt(pow(c[i].first-c[j].first,2)+(pow(c[i].second-c[j].second,2)));
                double val=fun[i]-distance1;
                dp[i]=max(dp[j]+val,dp[i]);
            }
        }
        cout<<fixed<<setprecision(6)<<dp[n-1]<<endl;
    }
    return 0;
}
