//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int timer = 1;

    void dfs(int node,int parent,vector<bool>& vis,vector<int>adj[],int tin[],int low[],
    set<pair<int,int>>&  bridges)
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it:adj[node])
        {
            if(it == parent) continue;

            if(!vis[it])
            {
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node] = min(low[node],low[it]);

                //node-it
                if(low[it] > tin[node])
                {
                    bridges.insert({it,node});
                }
            }
            else
            {
                low[node] = min(low[node],low[it]);
            }
        }
    }
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        set<pair<int,int>>bridges;
        int tin[V];
        int low[V];
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
               dfs(i,-1,vis,adj,tin,low,bridges);
            }
        }
        
        if(bridges.find({c,d}) != bridges.end() || bridges.find({d,c}) != bridges.end())
        {
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends