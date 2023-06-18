//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];

            if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc] > grid[row][col])
            {
                ans = max(ans , 1+dfs(newr,newc,grid,dp));
            }
        }

        return dp[row][col] = ans;
    }
         
    int longestIncreasingPath(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));

        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans = max(ans , 1+dfs(i,j,grid,dp));
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
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends