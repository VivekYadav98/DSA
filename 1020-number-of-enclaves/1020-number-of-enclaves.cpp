class Solution {
public:
     bool safe(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<bool>>& visited)
    {
        visited[i][j] = true;
        
       if(safe(i-1,j,n,m) && mat[i-1][j] == 1 && !visited[i-1][j])
       {
           dfs(i-1,j,n,m,mat,visited);
       }
       
       if(safe(i,j-1,n,m) && mat[i][j-1] == 1 && !visited[i][j-1])
       {
           dfs(i,j-1,n,m,mat,visited);
       }
       
       if(safe(i,j+1,n,m) && mat[i][j+1] == 1 && !visited[i][j+1])
       {
           dfs(i,j+1,n,m,mat,visited);
       }
       
       if(safe(i+1,j,n,m) && mat[i+1][j] == 1 && !visited[i+1][j])
       {
           dfs(i+1,j,n,m,mat,visited);
       }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && grid[0][i] == 1)
            {
                dfs(0,i,n,m,grid,visited);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && grid[i][0] == 1)
            {
                dfs(i,0,n,m,grid,visited);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(!visited[n-1][i] && grid[n-1][i] == 1)
            {
                dfs(n-1,i,n,m,grid,visited);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i][m-1] && grid[i][m-1] == 1)
            {
                dfs(i,m-1,n,m,grid,visited);
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