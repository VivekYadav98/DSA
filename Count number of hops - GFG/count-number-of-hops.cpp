//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1000000007;
    long long int solve(int n,vector<long long int>& dp)
    {
        if(n==0)
        {
            return 1;
        }
        
        if(n<0)
        {
            return 0;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        return dp[n] = ((solve(n-1,dp))%mod + (solve(n-2,dp))%mod + (solve(n-3,dp))%mod)%mod;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long int>dp(n+1,-1);
        return solve(n,dp)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends