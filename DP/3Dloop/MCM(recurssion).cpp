//link:https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
#define ll long long
int MCM(int i,int j,int arr[]){
    if(i==j){
        return 0;
    }
    int min_val=INT_MAX;
    for(int k=i;k<j;k++){
        int local=MCM(i,k,arr)+MCM(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
        min_val=min(min_val,local);
    }
    return min_val;
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return MCM(1,N-1,arr);
        
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
