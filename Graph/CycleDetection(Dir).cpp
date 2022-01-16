// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int c,bool* vis,bool* dfs,vector<int> adj[]){
        vis[c]=true;
        dfs[c]=true;
        for(auto x:adj[c]){
            if(!vis[x]){
                if(helper(x,vis,dfs,adj)){
                    return true;
                }
            }
            else if(dfs[x]){
                return true;
            }
        }
        dfs[c]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool *vis=new bool[V];
        bool *dfs=new bool[V];
        for(int i=0;i<V;i++){
            vis[i]=false;
            dfs[i]=false;
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i,vis,dfs,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
