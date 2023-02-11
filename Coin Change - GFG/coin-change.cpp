//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solve(int ind,int target,int nums[],vector<vector<long long int>>& dp)
	{
	    if(ind == 0)
	    {
	        return(target%nums[0] == 0);
	    }
	    
	    if(dp[ind][target] != -1)
	    {
	        return dp[ind][target];
	    }
	    
	    long long int notPick = solve(ind-1,target,nums,dp);
	    long long int pick = 0;
	    if(target >= nums[ind])
	    {
	        pick = solve(ind,target-nums[ind],nums,dp);
	    }
	    return dp[ind][target] = pick+notPick;
	}
	
    long long int count(int coins[], int N, int sum) {
	    vector<vector<long long int>>dp(N,vector<long long int>(sum+1,-1));
	    return solve(N-1,sum,coins,dp);
	    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends