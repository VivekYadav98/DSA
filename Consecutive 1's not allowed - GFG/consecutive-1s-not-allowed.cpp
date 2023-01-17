//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	 long long mod = 1000000007;
// 	 int solveRec(int n)
// 	 {
// 	   if(n == 1)
// 	    {
// 	        return 2;
// 	    }
// 	    if(n == 2)
// 	    {
// 	        return 3;
// 	    }
	    
// 	    return ((countStrings(n-1))%mod + (countStrings(n-2))%mod)%mod;
// 	 }
	 
	 
	 int solveMem(int n,vector<long long>& dp)
	 {
	   if(n == 1)
	    {
	        return 2;
	    }
	    if(n == 2)
	    {
	        return 3;
	    }
	    
	    if(dp[n] != -1)
	    {
	        return dp[n];
	    }
	    
	    return dp[n] = ((solveMem(n-1,dp))%mod + (solveMem(n-2,dp))%mod)%mod;
	 }
	 
	ll countStrings(int n) {
	   vector<long long>dp(n+1,-1);
	   return solveMem(n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends