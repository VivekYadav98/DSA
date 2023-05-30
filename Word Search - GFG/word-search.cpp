//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int row,int col,int ind,string& word,vector<vector<char>>& board,vector<vector<bool>>& vis)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(ind == word.size())
        {
            return true;
        }
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && word[ind] == board[newr][newc])
            {
                vis[newr][newc] = true;
                if(dfs(newr,newc,ind+1,word,board,vis))
                {
                    return true;
                }
            }
        }
        
        vis[row][col] = false;
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    int ind = 1;
                    if(dfs(i,j,ind,word,board,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends