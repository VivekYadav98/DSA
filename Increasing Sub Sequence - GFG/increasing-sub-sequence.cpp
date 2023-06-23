//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int solve(int i,int prev,string& s,vector<vector<int>>& dp)
    {
        if(i>=s.length())
        {
            return 0;
        }
        
        if(dp[i][prev+1] != -1)
        {
            return dp[i][prev+1];
        }
        
        int ans = solve(i+1,prev,s,dp);
        
        if(prev == -1 || s[i] > s[prev])
        {
            ans = max(ans,1+solve(i+1,i,s,dp));
        }
        return dp[i][prev+1] = ans;
    }
    
    int maxLength(string S)
    {
        int n = S.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,S,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends