//link:https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n<=2){
            return n;
        }
        
        
        int  mod=1e9+7;
        long long int dp[n+1]={0};
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            
            dp[i]=((dp[i-1]%mod)+(((i-1)%mod)*(dp[i-2]%mod))%mod)%mod;
            
        }
        
        return dp[n];
        
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
