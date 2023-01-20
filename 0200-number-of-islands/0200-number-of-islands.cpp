class Solution {
public:
    bool safe(int i,int j,int n,int m)
  {
      if(i<n && i>=0 && j<m && j>=0)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
  
  void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int n,int m)
  {
      visited[i][j] = true;
      
      if(safe(i-1,j,n,m) && !visited[i-1][j] && grid[i-1][j] == '1')
      {
          dfs(grid,visited,i-1,j,n,m);
      }
           
      if(safe(i,j-1,n,m) && !visited[i][j-1] && grid[i][j-1] == '1')
      {
          dfs(grid,visited,i,j-1,n,m);
      }
      
      if(safe(i,j+1,n,m) && !visited[i][j+1] && grid[i][j+1] == '1')
      {
          dfs(grid,visited,i,j+1,n,m);
      }
       
      if(safe(i+1,j,n,m) && !visited[i+1][j] && grid[i+1][j] == '1')
      {
          dfs(grid,visited,i+1,j,n,m);
      }
  }
  
    
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};