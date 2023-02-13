//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
   int solve(int ind,int target,vector<int>& A,vector<vector<int>>& dp)
   {
       if(ind==0)
       {
           if(target == 0 && A[0] == 0)
           {
               return 2;
           }
           if(target == 0 || target == A[0])
           {
               return 1;
           }
           return 0;
       }
       
       if(dp[ind][target] != -1)
       {
           return dp[ind][target];
       }
       
       int notPick = solve(ind-1,target,A,dp);
       int pick = 0;
       if(A[ind] <= target)
       {
           pick = solve(ind-1,target-A[ind],A,dp);
       }
       return dp[ind][target] = pick+notPick;
   }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        int totalSum=0;
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            totalSum += A[i];
        }
        int sum = (totalSum-target)/2;
        
        if((totalSum-target) < 0 || (totalSum-target)%2 != 0)
        {
            return 0;
        }
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,A,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends