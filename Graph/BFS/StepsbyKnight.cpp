//link:https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position
    bool isvalid(int i,int j,int N){
        return ((i<=N && i>0) && (j<=N && j>0));
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int arr1[2]={1,-1};
	    int arr2[2]={2,-2};
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    int steps=0;
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    while(!q.empty()){
	        
	        int size=q.size();
	        while(size--){
	            pair<int,int> val=q.front();
	            if(val.first==TargetPos[0] && val.second==TargetPos[1])
	            return steps;
	            q.pop();
	            
	            for(int i=0;i<2;i++){
	                for(int j=0;j<2;j++){
	                    if(isvalid(val.first+arr1[i],val.second+arr2[j],N) && !vis[val.first+arr1[i]][val.second+arr2[j]]){
	                       q.push({val.first+arr1[i],val.second+arr2[j]});
	                       vis[val.first+arr1[i]][val.second+arr2[j]]=1;
	                    }
	                    if(isvalid(val.first+arr2[j],val.second+arr1[i],N) && !vis[val.first+arr2[j]][val.second+arr1[i]]){
	                       q.push({val.first+arr2[j],val.second+arr1[i]});
	                       vis[val.first+arr2[j]][val.second+arr1[i]]=1;
	                    }
	                 }
	               }
	            
	        }
	        steps++;
	        
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
