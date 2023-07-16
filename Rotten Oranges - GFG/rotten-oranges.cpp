//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size(),m = grid[0].size();
        
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
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        int ans = 0;
        while(!q.empty())
        {
            bool flag = false;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int newr = row+dr[k];
                    int newc = col+dc[k];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] == 1)
                    {
                        flag = true;
                        grid[newr][newc] = 2;
                        q.push({newr,newc});
                    }
                }
            }
            
            if(flag == true)
            {
                ans++;
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
        
        return ans;
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