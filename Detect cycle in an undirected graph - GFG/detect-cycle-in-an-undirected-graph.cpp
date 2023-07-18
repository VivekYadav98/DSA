//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,int>vis,parent;
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                
                for(auto it:adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it] = true;
                        parent[it] = node;
                        q.push(it);
                    }
                    else if(parent[node] != it)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends