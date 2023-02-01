//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
    public:
    vector<int>parent,rank;
       DisjointSet(int n)
       {
           rank.resize(n+1,0);
           parent.resize(n+1);
           for(int i=0;i<=n;i++)
           {
               parent[i] = i;
           }
       }
       
       int findUpar(int node)
       {
           if(node == parent[node])
           {
               return node;
           }
           
           return findUpar(parent[node]);
       }
       
       void unionByRank(int u,int v)
       {
           int ulpU = findUpar(u);
           int ulpV = findUpar(v);
           
           if(ulpU == ulpV)
           {
               return;
           }
           
           if(rank[ulpU] < rank[ulpV])
           {
               parent[ulpU] = ulpV;
           }
           else if(rank[ulpV] < rank[ulpU])
           {
               parent[ulpV] = ulpU;
           }
           else
           {
               parent[ulpV] = ulpU;
               rank[ulpU]++;
           }
       }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       DisjointSet ds(V);
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
               if(adj[i][j] == 1)
               {
                   ds.unionByRank(i,j);
               }
           }
       }
       
       int count = 0;
       for(int i=0;i<V;i++)
       {
           if(ds.parent[i] == i)
           {
               count++;
           }
       }
       return count;
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