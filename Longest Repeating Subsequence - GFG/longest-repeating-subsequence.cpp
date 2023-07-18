//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp)
	    {
	        if(i==0 || j==0)
	        {
	            return 0;
	        }
	        
	        if(dp[i][j] != -1)
	        {
	            return dp[i][j];
	        }
	        
	        if(i != j && s[i-1] == t[j-1])
	        {
	            return dp[i][j] = 1+solve(i-1,j-1,s,t,dp);
	        }
	        else
	        {
	            return dp[i][j] = max(solve(i-1,j,s,t,dp) , solve(i,j-1,s,t,dp));
	        }
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		    return solve(n,n-1,str,str,dp);
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