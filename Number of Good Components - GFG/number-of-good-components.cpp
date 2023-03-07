//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,int& vertex,int& edges,vector<bool>& vis)
    {
        vis[node] = true;
        vertex++;
        
        for(auto it:adj[node])
        {
            edges++;
            if(!vis[it])
            {
                dfs(it,adj,vertex,edges,vis);
            }
        }
    }
    
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
      int ans = 0;
      vector<bool>vis(V+1,false);
      for(int i=1;i<=V;i++)
      {
          if(!vis[i])
          {
             int vertex = 0,edges=0;
             dfs(i,adj,vertex,edges,vis);
             edges = edges/2;
             
             if(edges == (vertex*(vertex-1))/2)
             {
                 ans++;
             }
          }
      }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends