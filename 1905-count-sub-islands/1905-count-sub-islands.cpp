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
    
    void dfs(vector<vector<int>>& grid2,vector<vector<bool>>& visited,
             int i,int j)
    {
        int n = grid2.size();
        int m = grid2[0].size();
        
        visited[i][j] = true;
        
        if(safe(i-1,j,n,m) && !visited[i-1][j] && grid2[i-1][j] == 1)
        {
          dfs(grid2,visited,i-1,j);
        }
           
          if(safe(i,j-1,n,m) && !visited[i][j-1] && grid2[i][j-1] == 1)
          {
              dfs(grid2,visited,i,j-1);
          }

          if(safe(i,j+1,n,m) && !visited[i][j+1] && grid2[i][j+1] == 1)
          {
              dfs(grid2,visited,i,j+1);
          }

          if(safe(i+1,j,n,m) && !visited[i+1][j] && grid2[i+1][j] == 1)
          {
              dfs(grid2,visited,i+1,j);
          }
        
    } 
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j] == 1 && grid1[i][j] != 1)
                { 
                    dfs(grid2,visited,i,j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid2[i][j] == 1)
                { 
                    dfs(grid2,visited,i,j);
                     count++;
                }
            }
        }
        return count;
    }
};