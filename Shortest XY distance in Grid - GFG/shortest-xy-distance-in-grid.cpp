//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j] == 'X')
                {
                    q.push({0,{i,j}});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            for(int k=0;k<size;k++)
            {
                int dis = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                for(int i=0;i<4;i++)
                {
                    int newr = row+dr[i];
                    int newc = col+dc[i];
                    
                    if(newr>=0 && newr<N && newc>=0 && newc<M && 1+dis < dist[newr][newc])
                    {
                        dist[newr][newc] = 1+dis;
                        q.push({1+dis,{newr,newc}});
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j] == 'Y')
                {
                  ans = min(ans,dist[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends