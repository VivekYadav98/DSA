//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int N = grid.size();
        int M = grid[0].size();
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        
        vector<vector<int>>cost(N,vector<int>(M,INT_MAX));
        cost[0][0] = grid[0][0];
        
        while(!pq.empty())
        {
            int temp = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int newr = row+dr[i];
                int newc = col+dc[i];
                
                if(newr>=0 && newr<N && newc>=0 && newc<M && grid[newr][newc]+temp < cost[newr][newc])
                {
                    cost[newr][newc] = grid[newr][newc] + temp;
                    pq.push({cost[newr][newc],{newr,newc}});
                }
            }
        }
        return cost[N-1][M-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends