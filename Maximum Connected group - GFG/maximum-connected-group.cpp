//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
  bool isValid(int newr,int newc,int n)
  {
      return (newr>=0 && newr<n && newc>=0 && newc<n);
  }
  
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col] == 0) continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                for(int i=0;i<4;i++)
                {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1)
                    {
                        int u = row*n + col;
                        int v = newr*n + newc;
                        ds.unionBySize(u,v);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col] == 1) continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int>components;
                
                for(int i=0;i<4;i++)
                {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1)
                    {
                        components.insert(ds.findUpar(newr*n+newc));
                    }
                }
                
                int sizeTotal = 1;
                for(auto it:components)
                {
                    sizeTotal += ds.size[it];
                    mx = max(mx,sizeTotal);
                }
            }
        }
        
        for(int cell=0;cell<n*n;cell++)
        {
            mx = max(mx,ds.size[ds.findUpar(cell)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends