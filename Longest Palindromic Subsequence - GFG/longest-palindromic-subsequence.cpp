//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string A,string B,int m,int n,vector<vector<int>>& dp)
  {
      if(m == 0 && n == 0)
      {
          return 0;
      }
      else if(m<=0 || n<=0)
      {
          return 0;
      }
      
      if(dp[m][n] != -1)
      {
          return dp[m][n];
      }
      
      if(A[m-1] == B[n-1])
      {
          return dp[m][n] = 1+solve(A,B,m-1,n-1,dp);
      }
      else
      {
          return dp[m][n] = max(solve(A,B,m-1,n,dp) , solve(A,B,m,n-1,dp));
      }
  }
  
    int longestPalinSubseq(string A) {
        string B = A;
        int m = A.length();
        int n = B.length();
        
        if(n == 1)
        {
            return 1;
        }
        
        reverse(B.begin(),B.end());
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(A,B,m,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends