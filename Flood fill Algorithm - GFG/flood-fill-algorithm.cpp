//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        int n = image.size(),m = image[0].size();
        q.push({sr,sc});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                vis[row][col] = true;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int newr = row+dr[k];
                    int newc = col+dc[k];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc] == color && !vis[newr][newc])
                    {
                        image[newr][newc] = newColor;
                        q.push({newr,newc});
                    }
                }
            }
        }
        
       return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends