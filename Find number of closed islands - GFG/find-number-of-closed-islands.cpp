//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    
    void dfs(int row,int col,vector<vector<int>>& matrix,vector<vector<bool>>& vis,int N,int M)
    {
        vis[row][col] = true;
        
        for(int k=0;k<4;k++)
        {
            int newr = row + dr[k];
            int newc = col + dc[k];
            
            if(newr>=0 && newr<N && newc>=0 && newc<M && !vis[newr][newc] && matrix[newr][newc] == 1)
            {
                dfs(newr,newc,matrix,vis,N,M);
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<bool>>vis(N,vector<bool>(M,false));
        
        for(int i=0;i<M;i++)
        {
            if(matrix[0][i] == 1 && !vis[0][i])
            {
                dfs(0,i,matrix,vis,N,M);
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(matrix[i][0] == 1 && !vis[i][0])
            {
                dfs(i,0,matrix,vis,N,M);
            }
        }
        
        for(int i=0;i<M;i++)
        {
            if(matrix[N-1][i] == 1 && !vis[N-1][i])
            {
                dfs(N-1,i,matrix,vis,N,M);
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(matrix[i][M-1] == 1 && !vis[i][M-1])
            {
                dfs(i,M-1,matrix,vis,N,M);
            }
        }
        
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j] == 1 && vis[i][j] == false)
                {
                    ans++;
                    dfs(i,j,matrix,vis,N,M);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends