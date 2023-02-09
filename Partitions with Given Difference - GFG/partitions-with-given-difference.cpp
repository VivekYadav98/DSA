//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
   int solve(int ind,int target,vector<int>& arr,vector<vector<int>>& dp)
   {
       if(ind < 0)
       {
           return (target == 0); 
       }
       
       if(dp[ind][target] != -1)
       {
           return dp[ind][target];
       }
       
       int notPick = solve(ind-1,target,arr,dp)%mod;
       int pick = 0;
       if(arr[ind] <= target)
       {
           pick = solve(ind-1,target-arr[ind],arr,dp)%mod;
       }
       return dp[ind][target] = (pick+notPick)%mod;
   }
   
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            totalSum += arr[i];
        }
        
        if((totalSum-d) < 0 || (totalSum-d)%2 != 0)
        {
            return false;
        }
        
        int target = (totalSum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends