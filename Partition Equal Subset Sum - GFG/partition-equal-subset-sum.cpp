//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[],int ind,int target,vector<vector<int>>& dp)
    {
        if(ind < 0)
	    {
	        return (target == 0);
	    }
    
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        
        bool notPick = solve(arr,ind-1,target,dp);
        bool pick = false;
        
        if(target >= arr[ind])
        {
            pick = solve(arr,ind-1,target-arr[ind],dp);
        }
        
        return dp[ind][target] = pick | notPick;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        
        if(sum%2 != 0)
        {
            return false;
        }
        
        sum /= 2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return solve(arr,N-1,sum,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends