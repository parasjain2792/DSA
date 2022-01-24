//O(N^2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Unit{
  public:
    ll start;
    ll end;
    ll profit;
};
bool comparator(Unit a,Unit b){
    return a.end<b.end;
}
int main(){
    // write your code here
    int n;
    cin>>n;
    Unit arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }
    ll dp[n+1];
    dp[0]=0;
    sort(arr,arr+n,comparator);
    for(int i=1;i<=n;i++){
        ll max_val=arr[i-1].profit;
        for(int j=i-1;j>0;j--){
            if(j && arr[j-1].end<=arr[i-1].start){
                max_val=max(max_val,dp[j]+arr[i-1].profit);
            }
            else{
                max_val=max(max_val,dp[j]);
            }
        }
        dp[i]=max_val;
    }
    ll max_val=0;
    for(int i=0;i<=n;i++){
        max_val=max(max_val,dp[i]);
    }
    cout<<max_val;
    return 0;
}
//O(NlogN)
