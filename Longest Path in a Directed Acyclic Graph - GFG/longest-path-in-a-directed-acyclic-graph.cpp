//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
          vector<vector<pair<int,int>>>adj(v);
          for(auto it:edges)
          {
              adj[it[0]].push_back({it[1],it[2]});
          }
          
          vector<int>dist(v,INT_MIN);
          dist[src] = 0;
          queue<pair<int,int>>q;
          q.push({0,src});
          
          while(!q.empty())
          {
              int node = q.front().second;
              int dis = q.front().first;
              q.pop();
              
              for(auto it:adj[node])
              {
                  int newDistance = it.second;
                  int newNode = it.first;
                  if(dis+newDistance > dist[newNode])
                  {
                      dist[newNode] = dis+newDistance;
                      q.push({dist[newNode],newNode});
                  }
              }
          }
          
          return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends