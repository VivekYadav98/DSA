//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	
	int solve(int i,int sum,int arr[],int n,vector<vector<int>>& dp)
    {
        if(sum<0)
        {
            return 0;
        }
        
        if(sum == 0 && i<n && arr[i] == 0)
        {
            return 2;
        }
        else if(sum == 0)
        {
            return 1;
        }
        
        if(i>=n)
        {
            return 0;
        }
        
        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        
        int ans1 = solve(i+1,sum-arr[i],arr,n,dp);
        int ans2 = solve(i+1,sum,arr,n,dp);
        return dp[i][sum] = ((ans1)%mod+(ans2)%mod)%mod;
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,sum,arr,n,dp);
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