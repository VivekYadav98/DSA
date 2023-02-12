//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  

	public:
	int solve(int i,int j,string s1,string s2,vector<vector<int>>& dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1])
        {
            return 1+solve(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j] = max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    int lcs = solve(n,m,str1,str2,dp);
	    int ans = n+m-2*lcs;
	    return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends