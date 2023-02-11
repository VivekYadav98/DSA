//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp)
	{
	    if(ind == 0)
	    {
	        if(target%nums[ind] == 0)
	        {
	            return target/nums[ind];
	        }
	        else
	        {
	            return 1e8;
	        }
	    }
	    
	    if(dp[ind][target] != -1)
	    {
	        return dp[ind][target];
	    }
	    int notPick = 0 + solve(ind-1,target,nums,dp);
	    int pick = INT_MAX;
	    if(target >= nums[ind])
	    {
	        pick = 1 + solve(ind,target-nums[ind],nums,dp);
	    }
	    return dp[ind][target] = min(pick,notPick);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    int n = nums.size();
	    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	    int ans = solve(n-1,amount,nums,dp);
	    if(ans >= 1e8)
	    {
	        return -1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends