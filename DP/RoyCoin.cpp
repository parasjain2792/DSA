#include<bits/stdc++.h>
using namespace std;
void add(int arr[],int l,int r){
    for(int i=l;i<=r;i++){
        arr[i]++;
    }
    return ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n+1]={0};
        int dp[m+1]={0};
        int c=m;
        while(c--){
            int l,r;
            cin>>l>>r;
            add(arr,l,r);
        }
        for(int i=1;i<=n;i++){
            dp[arr[i]]++;
        }
        for(int j=m-1;j>=0;j--){
            dp[j]+=dp[j+1];
        }
        int q;
        cin>>q;
        while(q--){
            int key;
            cin>>key;
            int ans=key>m?0:dp[key];
            cout<<ans<<endl;
        }
    }
    return 0;
}
