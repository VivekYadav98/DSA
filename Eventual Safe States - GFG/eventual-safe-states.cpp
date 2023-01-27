//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(vector<int>adj[],vector<bool>& vis,vector<bool>& pathVis,int node,vector<int>& check)
  {
      vis[node] = true;
      pathVis[node] = true;
      check[node] = 0;
      
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              if(dfs(adj,vis,pathVis,it,check))
              {
                  check[node] = 0;
                  return true;
              }
          }
          else if(vis[it] && pathVis[it] == true)
          {
              return true;
          }
      }
      
      check[node] = 1;
      pathVis[node] = false;
      return false;
  }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       vector<int>ans;
       vector<bool>vis(V,false);
       vector<bool>pathVis(V,false);
       vector<int>check(V,0);
       
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               dfs(adj,vis,pathVis,i,check);
           }
       }
       
       for(int i=0;i<V;i++)
       {
           if(check[i] == 1)
           {
               ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends