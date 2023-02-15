//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solveRec(int index,int buy,vector<long long>& prices,vector<vector<long long>>& dp)
    {
        if(index >= prices.size()) return 0;
        
        if(dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] + solveRec(index+1,0,prices,dp),0+solveRec(index+1,1,prices,dp));
        }
        else
        {
             profit = max(prices[index] + solveRec(index+2,1,prices,dp),0+solveRec(index+1,0,prices,dp));
        }

        return dp[index][buy] = profit;
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return solveRec(0,1,prices,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends