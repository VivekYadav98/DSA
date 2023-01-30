//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int,pair<int,int>>>q;
	    q.push({0,{0,0}});
	    vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
	    dist[0][0] = 0;
	    
	    if(A[0][0] == 0)
	    {
	        return -1;
	    }
	    
	    if(X==0 && Y==0)
	    {
	        return 0;
	    }
	    
	    int dr[] = {-1,0,0,1};
	    int dc[] = {0,-1,1,0};
	    
	    while(!q.empty())
	    {
	        int steps = q.front().first;
	        int r = q.front().second.first;
	        int c = q.front().second.second;
	        q.pop();
	        
	        if(r==X && c==Y)
	        {
	            return steps;
	        }
	        
	        for(int i=0;i<4;i++)
	        {
	            int newr = r+dr[i];
	            int newc = c+dc[i];
	            
	            if(newr>=0 && newr<N && newc>=0 && newc<M && A[newr][newc] == 1)
	            {
	                if(steps+1 < dist[newr][newc])
	                {
	                    dist[newr][newc] = steps+1;
	                    q.push({steps+1,{newr,newc}});
	                }
	            }
	        }
	    }
	    
	     return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends