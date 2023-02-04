//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
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
   
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        
        int count = 0;
        while(!q.empty())
        {
            bool flag = false;
            int size = q.size();
            for(int k=0;k<size;k++)
            {
                pair<int,int>node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                visited[row][col] = true;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                for(int i=0;i<4;i++)
                {
                    int newr = row+dr[i];
                    int newc = col+dc[i];
                    
                    if(safe(newr,newc,n,m) && !visited[newr][newc] && grid[newr][newc] == 1)
                    {
                        flag = true;
                        visited[newr][newc] = true;
                        q.push({newr,newc});
                        grid[newr][newc] = 2;
                    }
                }
            }
            if(flag == true)
            {
                count++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends