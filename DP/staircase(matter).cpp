#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
            int mod=1e9+7;
    int n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        continue;
    }
    if(n==2)
    {
        cout<<"2"<<endl;
        continue;
    }

    int arr[n+1]={0};
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=(((arr[i-1]+arr[i-2])%mod)+arr[i-3])%mod;
        
    }
    cout<<arr[n]<<endl;
    }
    return 0;
}
