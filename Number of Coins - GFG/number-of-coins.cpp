//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int i,int target,int coins[],int n,vector<vector<int>>& dp)
	{
	    if(target == 0)
	    {
	        return 0;
	    }
	    
	    if(i>=n)
	    {
	        return 1e8;
	    }
	    
	    if(dp[i][target] != -1)
	    {
	        return dp[i][target];
	    }
	    
	    int notTake = solve(i+1,target,coins,n,dp);
	    int take = INT_MAX;
	    if(target >= coins[i])
	    {
	        take = 1+solve(i,target-coins[i],coins,n,dp);
	    }
	    
	    
	    
	    return dp[i][target] = min(take,notTake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans = solve(0,V,coins,M,dp);
	    if(ans >= 1e8)
	    {
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends