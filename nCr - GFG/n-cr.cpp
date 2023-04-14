//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    
    int solve(int n,int r,vector<vector<int>>& dp)
    {
        if(n<r)
        {
            return 0;
        }
        
        if(n==0 || r==0)
        {
            return 1;
        }
        
        if(r == 1)
        {
            return n;
        }
        
        if(dp[n][r] != -1)
        {
            return dp[n][r];
        }
        
        return dp[n][r] = ((solve(n-1,r,dp))%mod + (solve(n-1,r-1,dp))%mod)%mod;
    }
    
    int nCr(int n, int r){
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return solve(n,r,dp)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends