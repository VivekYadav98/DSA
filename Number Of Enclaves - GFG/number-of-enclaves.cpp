//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool safe(int i,int j,int n,int m)
    {
        return(i>=0 && i<n && j>=0 && j<m);
    }
    
    void dfs(int row,int col,int n,int m,vector<vector<int>>& mat,vector<vector<bool>>& visited)
    {
        visited[row][col] = true;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];
            
            if(safe(newr,newc,n,m) && mat[newr][newc] == 1 && !visited[newr][newc])
            {
                dfs(newr,newc,n,m,mat,visited);
            }
        }
    }
    
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
       int n = grid.size();
       int m = grid[0].size();
       
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(!visited[i][j] && grid[i][j] == 1)
                    {
                        dfs(i,j,n,m,grid,visited);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    ans++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends