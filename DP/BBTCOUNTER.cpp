// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
     long long MOD=1e9+7;
       long long dp[h+1]={0};
       dp[0]=0;
       dp[1]=1;
       dp[2]=3;
       for(int i=3;i<=h;i++){
           
          dp[i]=(2*((dp[i-1]*dp[i-2])%MOD)%MOD)%MOD;
          dp[i]=(((dp[i-1]*dp[i-1])%MOD)+dp[i])%MOD;
       }
       return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends
