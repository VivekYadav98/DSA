//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(string S1,string S2,int n,int m)
    // {
    //     if(m==0)
    //     {
    //       return 1;
    //     }
        
    //     if(n == 0)
    //     {
    //         return 0;
    //     }
        
    //     if(S1[n-1] == S2[m-1])
    //     {
    //         return solve(S1,S2,n-1,m-1) + solve(S1,S2,n-1,m);
    //     }
    //     else
    //     {
    //         return solve(S1,S2,n-1,m);
    //     }
    // }
    
    int solveMem(string S1,string S2,int n,int m,vector<vector<int>>& dp)
    {
        if(m==0)
        {
           return 1;
        }
        
        if(n == 0)
        {
            return 0;
        }
        
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        
        if(S1[n-1] == S2[m-1])
        {
            return dp[n][m] = solveMem(S1,S2,n-1,m-1,dp) + solveMem(S1,S2,n-1,m,dp);
        }
        else
        {
            return dp[n][m] = solveMem(S1,S2,n-1,m,dp);
        }
    }

    int countWays(string S1, string S2){
        int n1 = S1.length();
        int n2 = S2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        return solveMem(S1,S2,n1,n2,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends