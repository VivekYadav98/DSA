//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& mark)
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];

            if(newr<0 || newr>=n || newc<0 || newc>=m)
            {
                continue;
            }

            if(grid[newr][newc] == 1 && mark[newr][newc] == 0)
            {
                mark[newr][newc] = 1;
                dfs(newr,newc,grid,mark);
            }
        }
    }

     
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>mark(n,vector<int>(m,0));
        int ans = 0;

        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 1)
            {
                mark[0][i] = 1;
                dfs(0,i,grid,mark);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
            {
                mark[i][0] = 1;
                dfs(i,0,grid,mark);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1] == 1)
            {
                mark[i][m-1] = 1;
                dfs(i,m-1,grid,mark);
            }
        }

        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i] == 1)
            {
                mark[n-1][i] = 1;
                dfs(n-1,i,grid,mark);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && mark[i][j] == 0)
                {
                    ans++;
                    dfs(i,j,grid,mark);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends