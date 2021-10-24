#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    // write your code here
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll num=((1<<k)-1);
        ll ans=n&num;
        cout<<ans<<endl;
    }
    return 0;
}
