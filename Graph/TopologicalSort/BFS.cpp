public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
    
        vector<int> inorder(V, 0);
        queue<int> q;
        
        for(int i = 0; i < V; i++)
        {
            for(int u: adj[i])
            {
                inorder[u]++;
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(inorder[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(q.empty() == false)
        {
            int u = q.front();
            
            res.push_back(u);
            
            for(int v: adj[u])
            {
                inorder[v]--;
                
                if(inorder[v] == 0)
                {
                    q.push(v);
                }
            }
            
            q.pop();
        }
        
        return res;
	}
};
