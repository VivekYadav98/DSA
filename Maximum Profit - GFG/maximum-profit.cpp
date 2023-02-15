//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int ind,int buy,int cap,int prices[],vector<vector<vector<int>>>& dp,int N)
    {
        if(cap == 0) return 0;
        if(ind == N) return 0;

        if(dp[ind][buy][cap] != -1)
        {
            return dp[ind][buy][cap];
        }
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[ind] + solve(ind+1,0,cap,prices,dp,N) , 0 + solve(ind+1,1,cap,prices,dp,N));
        }
        else
        {
            profit = max(prices[ind] + solve(ind+1,1,cap-1,prices,dp,N) , 0 + solve(ind+1,0,cap,prices,dp,N));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solve(0,1,K,A,dp,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends