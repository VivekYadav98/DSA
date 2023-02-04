//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
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
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<int>>visited(n,vector<int>(m,false));
	    int count = 0;
        
        while(!q.empty())
        {
            count = q.front().second;
            int size = q.size();
            
            for(int k=0;k<size;k++)
            {
                 int row = q.front().first.first;
                 int col = q.front().first.second;
                 q.pop();
                 
                 if(!visited[row][col])
                 {
                    visited[row][col] = true;
                    ans[row][col] = count;
                     
                     
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,1,0,-1};
                    
                    for(int i=0;i<4;i++)
                    {
                        int newr = row+dr[i];
                        int newc = col+dc[i];
                        
                        if(safe(newr,newc,n,m))
                        {
                            q.push({{newr,newc},count+1});
                        }
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