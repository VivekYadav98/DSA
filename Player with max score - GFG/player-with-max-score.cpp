//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[1001][1001][2];
    int solve(int i,int j,int turn,int nums[],int n)
    {
        if(i>j)
        {
            return 0;
        }
        
        if(dp[i][j][turn] != -1)
        {
            return dp[i][j][turn];
        }

        if(turn == 1)
        {
            return dp[i][j][turn] = max(nums[i]+solve(i+1,j,0,nums,n) , nums[j]+solve(i,j-1,0,nums,n));
        }
        else
        {
            return dp[i][j][turn] = min(solve(i+1,j,1,nums,n) , solve(i,j-1,1,nums,n));
        }
    }

    bool is1winner(int N,int arr[]) {
        int score1 = 0,score2 = 0;
        memset(dp,-1,sizeof(dp));
        score1 = solve(0,N-1,1,arr,N);
        
        for(int i=0;i<N;i++)
        {
            score2 += arr[i];
        }
        
        score2 -= score1;
        
        return (score1 >= score2);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends