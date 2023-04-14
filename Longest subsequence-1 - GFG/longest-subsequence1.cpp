//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int prev,int n,int arr[],vector<int>& dp)
    {
        if(i>=n)
        {
            return 0;
        }
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        int pick = INT_MIN,notPick = INT_MIN;
        if(prev == -1 || abs(arr[i]-prev) == 1)
        {
            pick = 1+solve(i+1,arr[i],n,arr,dp);
        }
        
        notPick = solve(i+1,prev,n,arr,dp);
        return max(pick,notPick);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N+1,-1);
        return solve(0,-1,N,A,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends