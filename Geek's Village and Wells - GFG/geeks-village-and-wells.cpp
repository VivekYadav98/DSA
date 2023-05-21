//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int> , int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j] == 'W')
                {
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            
            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};
            
            for(int k=0;k<4;k++)
            {
                int newr = row+dr[k];
                int newc = col+dc[k];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    if((c[newr][newc] == 'H' || c[newr][newc] == '.') && ans[newr][newc] > (cnt+1)*2)
                    {
                        ans[newr][newc] = min(ans[newr][newc] , (cnt+1)*2);
                        q.push({{newr,newc},cnt+1});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j] == INT_MAX)
                {
                    ans[i][j] = -1;
                }
                if(c[i][j] == 'N' || c[i][j] == '.')
                {
                    ans[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends