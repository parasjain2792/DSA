// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        for(int i=0;i<=k;i++){
            dp[1][i]=i;
        }
        
        
      for(int j=0;j<=1;j++)
       {
           for(int i=0;i<=n;i++){
               dp[i][j]=j;
           }
       }
       for(int i=2;i<=n;i++){
           
           for(int j=2;j<=k;j++){
              int m=j-1;
              int k=0;
              int minval=INT_MAX;
              while(k<=m){
                  int maxval=max(dp[i-1][k++],dp[i][m--]);
                  minval=min(minval,maxval);
              } 
              dp[i][j]=minval+1;
           }
       }
        
        return dp[n][k];
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
