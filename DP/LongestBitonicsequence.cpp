//link:https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    int n=arr.size();
	    int dp[n]={0};
        int dp2[n]={0};
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i] && dp[i]<=dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
        }
       
        for(int i=n-1;i>=0;i--){
            dp2[i]=1;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i] && dp2[i]<=dp2[j])
                    dp2[i]=dp2[j]+1;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<dp2[i]<<" ";
        // }
        int max_val=1;
        for(int i=0;i<n;i++){
            int lmax=0;
            lmax=(dp[i]+dp2[i])-1;
            max_val=max(max_val,lmax);
        }
        return max_val;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
