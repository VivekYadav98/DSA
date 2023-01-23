//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	 int solve(string& s1,string& s2,int m,int n,vector<vector<int>>& dp)
    {
        if(m==0 || n==0)
        {
            return 0;
        }
       
        
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        
        if(s1[m-1] == s2[n-1] && (m-1) != (n-1))
        {
            return dp[m][n] = 1+solve(s1,s2,m-1,n-1,dp);
        }
        else
        {
            return dp[m][n] = max(solve(s1,s2,m-1,n,dp),solve(s1,s2,m,n-1,dp));
        }
    }
    
		int LongestRepeatingSubsequence(string str){
		   int n = str.length();
		   vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		   return solve(str,str,n,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends