//link:https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool DFScycle(int val,int prev,vector<int> adj[],bool* vis){
        vis[val]=true;
        for(auto i:adj[val]){
            if(!vis[i]){
               if(DFScycle(i,val,adj,vis)){
                return true;
               }
            }
            else if(i!=prev){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool* vis=new bool[V+1];
        for(int i=0;i<=V;i++){
            vis[i]=false;
        }
        for(int i=1;i<V;i++){
            if(!vis[i]){
                if(DFScycle(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
