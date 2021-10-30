#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll v;
        cin>>v;
        ll mod=1e9+7;
        ll supply[v+1]={0};
        supply[0]=1;
        for(int i=0;i<n;i++){
            for(int j=arr[i];j<=v;j++){
                supply[j]=(supply[j]+supply[j-arr[i]])%mod;
            }
        }
        cout<<supply[v]<<endl;
    }
    return 0;
}
