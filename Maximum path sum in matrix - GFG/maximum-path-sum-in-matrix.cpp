//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>>& matrix,int N,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || i>=N || j>=N)
        {
            return INT_MIN;
        }
        
        if(i==0)
        {
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int cost1 = matrix[i][j] + solve(i-1,j,matrix,N,dp);
        int cost2 = matrix[i][j] + solve(i-1,j+1,matrix,N,dp);
        int cost3 = matrix[i][j] + solve(i-1,j-1,matrix,N,dp);
        
        return dp[i][j] = max(cost1,max(cost2,cost3));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            int cost = solve(N-1,i,Matrix,N,dp);
            ans = max(ans,cost);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends