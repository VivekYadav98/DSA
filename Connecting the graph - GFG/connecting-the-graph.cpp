//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edge) {
         DisjointSet ds(n);
         int cntExtra = 0;
       for(int i=0;i<edge.size();i++)
       {
           int u = edge[i][0];
           int v = edge[i][1];
           
           if(ds.findUpar(u) == ds.findUpar(v))
           {
               cntExtra++;
           }
           else
           {
              ds.unionByRank(u,v);
           }
       }
       
       int countC = 0;
       for(int i=0;i<n;i++)
       {
           if(ds.parent[i] == i)
           {
               countC++;
           }
       }
       
       int ans = countC-1;
       
       if(cntExtra >= ans)
       {
           return ans;
       }
       else
       {
           return -1;
       }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends