//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    unordered_map<int,int>m;
    int solve(int i,vector<int>& nums,int sum,vector<vector<int>>& dp)
    {
        if(i>=nums.size())
        {
            m[sum]++;
            return 0;
        }
        
        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        
        int take = solve(i+1,nums,sum+nums[i],dp);
        int notTake = solve(i+1,nums,sum,dp);
        return dp[i][sum] = take+notTake;
    }
    
	vector<int> DistinctSum(vector<int>nums){
	    vector<int>ans;
	    int n = nums.size();
	    vector<vector<int>>dp(n+1,vector<int>(10001,-1));
	    solve(0,nums,0,dp);
	    
	    for(auto it:m)
	    {
	        ans.push_back(it.first);
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends