//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod = 1000000007;
    int solve(int n,vector<int>& dp)
    {
        if(n == 0)
        {
            return 1;
        }
        
        if(n < 0)
        {
            return 0;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = ((solve(n-1,dp))%mod + (solve(n-2,dp))%mod)%mod;
    }
    
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i] = ((dp[i-1])%mod + (dp[i-2])%mod)%mod;
        }
    
        return dp[n]%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends