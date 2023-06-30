//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool solve(int i,vector<int>&A,int target,vector<vector<int>>& dp)
    {
       if(target == 0)
       {
           return true;
       }
       
       if(i>=A.size())
       {
           return false;
       }
       
       if(dp[i][target] != -1)
       {
           return dp[i][target];
       }
       
       bool notTake = solve(i+1,A,target,dp);
       bool take = false;
       
       if(target >= A[i])
       {
           take = solve(i+1,A,target-A[i],dp);
       }
       
       return dp[i][target] = (take || notTake);
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
       return solve(0,arr,k,dp);   
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends