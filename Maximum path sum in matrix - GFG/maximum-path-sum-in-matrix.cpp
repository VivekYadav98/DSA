//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(i>=n || j>=n || j<0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int ans1 = matrix[i][j] + solve(i+1,j,n,matrix,dp);
        int ans2 = matrix[i][j] + solve(i+1,j-1,n,matrix,dp);
        int ans3 = matrix[i][j] + solve(i+1,j+1,n,matrix,dp);
        return dp[i][j] = max(ans1,max(ans2,ans3));
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        int ans = INT_MIN;
        for(int i=0;i<N;i++)
        {
            ans = max(ans,solve(0,i,N,Matrix,dp));
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