//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool solve(int i,int k,int target,vector<int>& nums,vector<vector<vector<int>>>& dp)
    {
        if(k == 0 && target == 0)
        {
            return true;
        }
        
        if(i>=nums.size() || k<0 || target<0)
        {
            return false;
        }
        
        if(dp[i][k][target] != -1)
        {
            return dp[i][k][target];
        }
        
        if(solve(i,k-1,target-nums[i],nums,dp))
        {
            return dp[i][k][target] = true;
        }
        
        if(solve(i+1,k,target,nums,dp))
        {
            return dp[i][k][target] = true;
        }
        return dp[i][k][target] = false;
    }
    
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return solve(0,K,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends