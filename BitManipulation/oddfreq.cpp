#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    // write your code here
    ll t;
    cin>>t;
    while(t--){
        ll n,ans;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
        }
        ans=0;
        for(int i=0;i<n;i++){
            ans=ans ^ arr[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
