//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            auto i = q.front();
            q.pop();
            int stops = i.first;
            int node = i.second.first;
            int dis = i.second.second;
            
            for(auto it:adj[node])
            {
                 if(stops<=K)
                 {
                     if(dis + it.second < dist[it.first])
                     {
                         dist[it.first] = dis + it.second;
                         q.push({stops+1,{it.first,dist[it.first]}});
                     }
                 }
                
            }
        }
        
        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return dist[dst];
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends