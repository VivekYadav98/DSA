//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int i,int n,int sum,int arr[],vector<vector<int>>& dp)
	{
	    if(i>=n)
	    {
	        return 0;
	    }
	    
	    if(dp[i][sum] != -1)
	    {
	        return dp[i][sum]%mod;
	    }
	    
	    int pick = 0;
	    if(sum >= arr[i])
	    {
	        if(sum == arr[i])
	        {
	            pick++;
	        }
	        pick += solve(i+1,n,sum-arr[i],arr,dp);
	        pick = pick%mod;
	    }
	    
	    int notPick = solve(i+1,n,sum,arr,dp);
	    return dp[i][sum] = (pick+notPick)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       return solve(0,n,sum,arr,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends