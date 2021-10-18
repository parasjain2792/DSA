// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    #define ll long long 
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s, string t, int m, int n)
    {
        //code here
        n=s.size();
        m=t.size();
        ll **dp=new ll*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new ll[m+1];
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=dp[0][j-1]+1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends
