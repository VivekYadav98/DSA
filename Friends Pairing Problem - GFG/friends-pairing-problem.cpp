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
        if(n == 1)
        {
            return 1;
        }
       
        long long int prev2 = 1;
        long long int prev1 = 2;
        
        
        for(int i=3;i<=n;i++)
        {
            long long int curr = (prev1 + ((i-1)*prev2)%mod)%mod;
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1%mod;
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