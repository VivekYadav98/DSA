//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int i,int val[],int wt[],int cap,int n,vector<vector<int>>& dp)
    {
        if(cap == 0 || i>=n)
        {
            return 0;
        }
        
        if(dp[i][cap] != -1)
        {
            return dp[i][cap];
        }
        
        int take = 0;
        if(cap>=wt[i])
        {
            take = val[i] + solve(i+1,val,wt,cap-wt[i],n,dp);
        }
        
        int notTake = solve(i+1,val,wt,cap,n,dp);
        
        return dp[i][cap] = max(take,notTake);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(0,val,wt,W,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends