// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        int **dp=new int*[n-1];
        for(int i=0;i<n-1;i++){
            dp[i]=new int[n-1];
            for(int j=0;j<n-1;j++){
                dp[i][j]=0;
            }
        }
        for(int gap=0;gap<n-1;gap++){
            for(int i=0,j=gap;j<n-1;j++,i++){
                if(gap==0){
                    dp[i][j]=0;
                }
                else if(gap==1){
                    dp[i][j]=arr[i]*arr[i+1]*arr[j+1];
                }
                else{
                    int min_val=INT_MAX;
                    for(int k=i;k<j;k++){
                        int l1=dp[i][k];
                        int r1=dp[k+1][j];
                        int m1=arr[i]*arr[k+1]*arr[j+1];
                        int t=l1+m1+r1;
                        min_val=min(min_val,t);
                    }
                    dp[i][j]=min_val;
                }
            }
        }
        //  for(int i=0;i<n-1;i++){
        //     for(int j=0;j<n-1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][n-2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
