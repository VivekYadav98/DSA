//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(),m = grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j] == 1)
	            {
    	            q.push({{i,j},0});
    	            ans[i][j] = 0;
	            }
	        }
	    }
	    
	    int dr[4] = {-1,0,1,0};
	    int dc[4] = {0,1,0,-1};
	    
	    while(!q.empty())
	    {
	        int size = q.size();
	        for(int k=0;k<size;k++)
	        {
	            int row = q.front().first.first;
    	        int col = q.front().first.second;
    	        int cnt = q.front().second;
    	        q.pop();
    	        
    	        for(int i=0;i<4;i++)
    	        {
    	            int newr = row+dr[i];
    	            int newc = col+dc[i];
    	            
    	            if(newr>=0 && newr<n && newc>=0 && newc<m && ans[newr][newc] > cnt+1)
    	            {
    	                ans[newr][newc] = cnt+1;
    	                q.push({{newr,newc},cnt+1});
    	            }
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends