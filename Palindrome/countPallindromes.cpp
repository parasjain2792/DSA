// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //Your code here
       int n=s.size();
       int N=s.size();
       int mod=1e9+7;
       int dp[n][n];
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j){
                   dp[i][j]=1;
               }
               else{
                   dp[i][j]=0;
               }
           }
       }
       for(int si=2;si<=N;si++){
           for(int i=0,j=si-1;j<N;j++,i++){
               if(s[i]==s[j]){
                   dp[i][j]=(((1+dp[i+1][j])%mod)+dp[i][j-1])%mod;
               }
               else{
                   dp[i][j]=(((dp[i+1][j]+dp[i][j-1])%mod)-dp[i+1][j-1]+mod)%mod;
               }
           }
       }
       return dp[0][n-1];
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
