//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        int N = arr.size();
        int M = arr[0].size();
        
        queue<pair<int,int>>q;
        q.push({start_x,start_y});
        
        vector<int>cost;
        int points = arr[start_x][start_y];
        int steps = 0;
        cost.push_back(points);
        steps++;
            
        vector<vector<bool>>vis(N,vector<bool>(M,false));        
    
        int dr[] = {-1,-2,-2,-1,1,2,2,1};
	    int dc[] = {-2,-1,1,2,2,1,-1,-2};
	    
        while(!q.empty())
        {
            int size = q.size();
            int points = 0;
            for(int i=0;i<size;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                vis[row][col] = true;
                
                for(int i=0;i<8;i++)
                {
                    int newr = row+dr[i];
                    int newc = col+dc[i];
                    
                    
                    if(newr >=0 && newr<N && newc>=0 && newc<M && !vis[newr][newc])
                    {
                        vis[newr][newc] = true;
                        q.push({newr,newc});
                        points += arr[newr][newc];
                    }
                }
            }
            
            cost.push_back(points);
        }
        
        int size=cost.size();
        int maxi=INT_MIN;
        int ans=0;
        
        // here we are basiclly moving like x+y steps.
        for(int i=size-1;i>=0;i--)
        {
            if(cost[i] + i < size)
            {
                cost[i]+=cost[cost[i]+i];
            }
            
            if(cost[i] >= maxi)
            {
                maxi=cost[i];
                ans=i;
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
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends