#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mod=1e9+7;
        int dp[n][101]={0};
        for(int i=0;i<n;i++){
            dp[i][arr[i]]=1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    for(int g=1;g<=100;g++){
                        int ng=gcd(max(arr[i],g),min(arr[i],g));
                        dp[i][ng]=(dp[i][ng]+dp[j][g])%mod;
                    }
                }   
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(dp[i][1]+sum)%mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
