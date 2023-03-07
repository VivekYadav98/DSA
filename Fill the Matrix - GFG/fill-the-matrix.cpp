//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        vector<vector<int>>mat(N,vector<int>(M,0));
        x--;
        y--;
        mat[x][y] = 1;
        queue<pair<int,int>>q;
        q.push({x,y});
        int ans = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int j=0;j<size;j++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                for(int i=0;i<4;i++)
                {
                    int newr = row+dr[i];
                    int newc = col+dc[i];
                    
                    if(newr>=0 && newr<N && newc>=0 && newc<M && mat[newr][newc] == 0)
                    {
                        mat[newr][newc] = 1;
                        q.push({newr,newc});
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends