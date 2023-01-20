class Solution {
public:
     bool safe(int i,int j,int n,int m)
  {
      if(i<m && i>=0 && j<n && j>=0)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
    
    void dfs(vector<vector<int>>& grid2,vector<vector<bool>>& visited,
             int i,int j,int n,int m)
    {
        visited[i][j] = true;
        
        if(safe(i-1,j,n,m) && !visited[i-1][j] && grid2[i-1][j] == 1)
        {
          dfs(grid2,visited,i-1,j,n,m);
        }
           
          if(safe(i,j-1,n,m) && !visited[i][j-1] && grid2[i][j-1] == 1)
          {
              dfs(grid2,visited,i,j-1,n,m);
          }

          if(safe(i,j+1,n,m) && !visited[i][j+1] && grid2[i][j+1] == 1)
          {
              dfs(grid2,visited,i,j+1,n,m);
          }

          if(safe(i+1,j,n,m) && !visited[i+1][j] && grid2[i+1][j] == 1)
          {
              dfs(grid2,visited,i+1,j,n,m);
          }
        
    } 
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] != 1)
                { 
                    dfs(grid2,visited,i,j,n,m);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid2[i][j] == 1)
                { 
                    count++;
                    dfs(grid2,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};