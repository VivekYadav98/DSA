//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9+7;
    int solve(int i,vector<int>& arr,int x,int sum,int target,vector<vector<int>>& dp)
    {
        if(i>=arr.size() || sum > target)
        {
            if(sum == target)
            {
                return 1;
            }
            return 0;
        }
        
        if(sum == target)
        {
            return 1;
        }
        
        if(dp[i][sum] != -1)
        {
            return dp[i][sum]%mod;
        }
        
        int take = 0,notTake = 0;
        for(int j=i+1;j<=arr.size();j++)
        {
            int num = pow(arr[i],x);
            return dp[i][sum] = ((solve(j,arr,x,sum+num,target,dp))%mod + (solve(j,arr,x,sum,target,dp))%mod)%mod; 
            
            // cout<<take<<" ";
        }
        
        // return take;
    }
    
    int numOfWays(int n, int x)
    {
        vector<int>arr;
        for(int i=1;pow(i,x)<=n;i++)
        {
            arr.push_back(i);
        }
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(n+1,-1));
        return solve(0,arr,x,0,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends