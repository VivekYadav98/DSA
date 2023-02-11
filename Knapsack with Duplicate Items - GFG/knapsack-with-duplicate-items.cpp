//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int W,int val[],int wt[],vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            return (W/wt[0])*val[0];
        }
        
        if(dp[ind][W] != -1)
        {
            return dp[ind][W];
        }
        
        int notPick = 0 + solve(ind-1,W,val,wt,dp);
        int pick = INT_MIN;
        if(W >= wt[ind])
        {
            pick = val[ind] + solve(ind,W-wt[ind],val,wt,dp);
        }
        return dp[ind][W] = max(pick,notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<int>prev(W+1,0);
        for(int w=0;w<=W;w++)
        {
            prev[w] = (w/wt[0])*val[0]; 
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int w=0;w<=W;w++)
            {
                int notPick = 0 + prev[w];
                int pick = INT_MIN;
                if(w >= wt[ind])
                {
                    pick = val[ind] + prev[w-wt[ind]];
                }
                prev[w] = max(pick,notPick);
            }
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends