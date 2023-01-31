//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            
            for(auto it:adj[node])
            {
                if(dis+it.second < dist[it.first])
                {
                    dist[it.first] = dis + it.second;
                    ways[it.first] += ways[node];
                    pq.push({dist[it.first],it.first});
                }
                else if(dis+it.second == dist[it.first])
                {
                    ways[it.first] += ways[node];
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends