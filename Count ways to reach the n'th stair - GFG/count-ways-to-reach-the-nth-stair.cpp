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
        int prev2 = 1;
        int prev1 = 1;
        
        for(int i=2;i<=n;i++)
        {
            int curr = (prev2+prev1)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
    
        return prev1%mod;
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