//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(vector<vector<pair<int,int>>>& adj,int node,vector<bool>& visited,stack<int>& s)
  {
      visited[node] = true;
      
      for(auto it:adj[node])
      {
          if(!visited[it.first])
          {
              dfs(adj,it.first,visited,s);
          }
      }
      
      s.push(node);
  }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<bool>visited(N,false);
        stack<int>s;
        
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                dfs(adj,0,visited,s);
            }
        }
        
        vector<int>dist(N,INT_MAX);
        dist[0] = 0;
        
        s.push(0);
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            for(auto it:adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends