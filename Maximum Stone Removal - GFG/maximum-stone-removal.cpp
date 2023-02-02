//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    vector<int>parent,rank,size;
       DisjointSet(int n)
       {
           rank.resize(n+1,0);
           parent.resize(n+1);
           size.resize(n+1,1);
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
       
       void unionBySize(int u,int v)
       {
           int ulpU = findUpar(u);
           int ulpV = findUpar(v);
           if(ulpU == ulpV)
           {
               return;
           }
           
           if(size[ulpU] > size[ulpV])
           {
               parent[ulpV] = ulpU;
               size[ulpU] += size[ulpV];
           }
           else
           {
               parent[ulpU] = ulpV;
               size[ulpV] += size[ulpU];
           }
       }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones)
        {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        
        for(auto it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto it:stoneNodes)
        {
            if(ds.findUpar(it.first) == it.first)
            {
                cnt++;
            }
        }
        
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends