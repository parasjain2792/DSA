// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    class Unit{
        public:
        int val;
        int pos;
    };
   static bool comparator(Unit a,Unit b){
        return a.val<b.val;
    }
    int dfs(int value,vector<bool>&vis,Unit arr[],int position){
        if(vis[position]){
            return 0;
        }
        vis[position]=1;
        int count=0;
        if(arr[position].pos!=position)
        count=dfs(arr[arr[position].pos].val,vis,arr,arr[position].pos)+1;
        return count;
    }
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	   // sort(nums.begin(),nums.end());
	    Unit arr[n];
	    for(int i=0;i<n;i++){
	        arr[i].val=nums[i];
	        arr[i].pos=i;
	    }
	    int count=0;
	    sort(arr,arr+n,comparator);
	    vector<bool> vis(n,0);
	    for(int i=0;i<n;i++){
	        if(!vis[i]){
	            int value=dfs(arr[i].val,vis,arr,i);
	          if(value){
	           count+=value-1; 
	          }
	        // cout<<i<<":"<<value<<endl;
	        }
	    }
	    return count;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
