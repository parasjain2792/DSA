//link:https://practice.geeksforgeeks.org/problems/257a9e27fb3e58255622c8dcb06e0919cc1c6c11/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &A,int n,int k){
        // Your code goes here
        int ps[n+1][n+1];
        for(int i=0;i<=n;i++){
            ps[i][0]=0;
            ps[0][i]=0;
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ps[i][j]=A[i-1][j-1]-ps[i-1][j-1]+ps[i-1][j]+ps[i][j-1];
                if(i>=k && j>=k){
                    ans=max(ans,ps[i][j]-ps[i-k][j]-ps[i][j-k]+ps[i-k][j-k]);
                }
            }
        }
        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends
