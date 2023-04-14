//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
     int solve(int i,int j,string s,string t,vector<vector<int>>& dp)
    {
        if(i <= 0 || j <= 0)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i-1] == t[j-1])
        {
            dp[i][j] = 1 + solve(i-1,j-1,s,t,dp);
        }
        else
        {
            dp[i][j] = max(solve(i-1,j,s,t,dp) , solve(i,j-1,s,t,dp));
        }
        return dp[i][j];
    }

    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(),B.end());
        int n = A.length();
        int m = n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,A,B,dp);
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