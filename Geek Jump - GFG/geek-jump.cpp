//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i,vector<int>& arr,int n,vector<int>& dp)
    {
        if(i == n-1)
        {
            return 0;
        }
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        int ans = INT_MAX;
        
        for(int j=i+1;j<i+3 && j<n;j++)
        {
            int cost = abs(arr[i]-arr[j]) + solve(j,arr,n,dp);
            ans = min(ans,cost);
        }
        return dp[i] = ans;
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return solve(0,height,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends