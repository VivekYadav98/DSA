//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool safe(int i,int j,int n,int m)
    {
        return(i>=0 && i<n && j>=0 && j<m);
    }
    
    void dfs(int row,int col,int n,int m,vector<vector<char>>& mat,vector<vector<bool>>& visited)
    {
        visited[row][col] = true;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];
            
            if(safe(newr,newc,n,m) && mat[newr][newc] == 'O' && !visited[newr][newc])
            {
                dfs(newr,newc,n,m,mat,visited);
            }
        }
    }
    
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(!visited[i][j] && mat[i][j] == 'O')
                    {
                        dfs(i,j,n,m,mat,visited);
                    }
                 }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            vector<char>temp;
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends