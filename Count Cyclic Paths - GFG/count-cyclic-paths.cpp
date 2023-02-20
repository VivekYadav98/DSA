//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int mod = 1000000007;
    long long int solve(int n,vector<long long int>& dp)
    {
        if(n==1) return 0;
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        if(n%2 == 0)
        {
            return dp[n] = (((solve(n-1,dp)%mod)*3)%mod + 3)%mod;
        }
        else
        {
            return dp[n] = (((solve(n-1,dp)%mod)*3)%mod - 3)%mod;
        }
    }
    int countPaths(int n){
        vector<long long int>dp(n+1,0);
        dp[1] = 0;
        for(int i=2;i<=n;i++)
        {
            if(i%2 == 0)
            {
                dp[i] = ((dp[i-1]*3)%mod + 3)%mod;
            }
            else
            {
                dp[i] = ((dp[i-1]*3)%mod - 3)%mod;
            }  
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends