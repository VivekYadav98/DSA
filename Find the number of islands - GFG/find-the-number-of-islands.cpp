//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
  {
      vis[row][col] = 1;
      queue<pair<int,int>>q;
      q.push({row,col});
      int n = grid.size();
      int m = grid[0].size();
        
      while(!q.empty())
      {
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          
          int dr[] = {-1,-1,0,1,1,1,0,-1};
          int dc[] = {0,1,1,1,0,-1,-1,-1};
          
          for(int i=0;i<8;i++)
          {
              int newr = row + dr[i];
              int newc = col + dc[i];
              
              if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc] == '1')
              {
                  vis[newr][newc] = 1;
                  q.push({newr,newc});
              }
          }
      }
  }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends