//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis)
    {
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>>newAdj(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1)
                {
                    newAdj[i].push_back(j);
                    newAdj[j].push_back(i);
                }
            }
        }
        
        vector<bool>vis(V,false);
        int ans = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,newAdj,vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends