//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int solve(vector<int>& a,int i,int j,vector<vector<int>>& dp)
        {
            if(i>j)
            {
                return 0;
            }
            
            if(dp[i][j] != -1)
            {
                return dp[i][j];
            }
            
            int ans = INT_MIN;
            for(int ind=i;ind<=j;ind++)
            {
                int cost = a[i-1]*a[ind]*a[j+1] + solve(a,i,ind-1,dp) + solve(a,ind+1,j,dp);
                ans = max(ans,cost);
            }
            return dp[i][j] = ans;
        }
        int maxCoins(int N, vector <int> &a)
        {
            a.insert(a.begin(),1);
            a.push_back(1);
            vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
            return solve(a,1,N,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends