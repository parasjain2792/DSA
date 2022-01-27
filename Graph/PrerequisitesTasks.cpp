//link:https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool cycle(vector<int> adj[],vector<bool> &vis,int val,vector<bool>& check ){
       vis[val]=true;
       check[val]=true;
        for(auto x:adj[val]){
            if(!vis[x]){
                if(cycle(adj,vis,x,check)){
                    return true;
                }
            }
            else if(check[x]){
                return true;
            }
        }
        check[val]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	        
	    }
	    vector<bool> vis(N,false);
	    vector<bool> check(N,false);
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(cycle(adj,vis,i,check)){
	               return false;
	            }
	             
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
