//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9+7;
    long long int solve(int n,vector<long long int>& dp)
    {
        if(n <= 2)
        {
            return n;
        }
        
        if(dp[n] != -1)
        {
            return dp[n]%mod;
        }
        
        return dp[n] = ((solve(n-1,dp))%mod + ((n-1)*(solve(n-2,dp))%mod)%mod)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long int>dp(n+1,-1);
        return solve(n,dp)%mod;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends