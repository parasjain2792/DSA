//link:https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int arr[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[V+1];
	    for(int i=1;i<=V;i++){
	        dp[i]=100000;
	    }
	    dp[0]=0;
	    for(int i=0;i<M;i++){
	        for(int j=arr[i];j<=V;j++){
	            int local=dp[j];
	            if(j%arr[i]==0){
	                local=min(local,j/arr[i]);
	            }
	            local=min(dp[j-arr[i]]+1,local);
	            dp[j]=local;
	        }
	    }
	    if(dp[V]==100000)
	    dp[V]=-1;
	    return dp[V];
	   
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
