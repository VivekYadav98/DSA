//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1e9+7;
    int solve(string& s,string& t,int i,int j,vector<vector<int>>& dp)
    {
        if(j == 0)
        {
            return 1;
        }
        if(i ==0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i-1] == t[j-1])
        {
            return dp[i][j] = ((solve(s,t,i-1,j-1,dp))%mod + (solve(s,t,i-1,j,dp))%mod)%mod;
        }
        else
        {
            return dp[i][j] = solve(s,t,i-1,j,dp)%mod;
        }
    }
    
    int subsequenceCount(string S, string T)
    {
       int n = S.length(),m=T.length();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return solve(S,T,n,m,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends