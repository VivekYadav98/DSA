//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long solve(int n,vector<long long>& dp)
    {
        if(n<=1)
        {
            return 1;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        return dp[n] = n*solve(n-1,dp);
    }
    long long nPr(int n, int r){
        if(n<r)
        {
            return 0;
        }
        
        vector<long long int>dp1(n+1,-1);
        vector<long long int>dp2(n-r+1,-1);
        long long int x = solve(n,dp1);
        long long int y = solve(n-r,dp2);
        return x/y;
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
        cout<<ob.nPr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends