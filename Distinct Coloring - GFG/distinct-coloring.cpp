//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int solve(int ind,int last,vector<vector<long long int>> &colors,vector<vector<long long int>>& dp)
    {
        if(ind == 0)
        {
            long long int mini = INT_MAX;
            for(int i=0;i<3;i++)
            {
                if(i != last)
                {
                    mini = min(mini,colors[0][i]);
                }
            }
            return mini;
        }
        
        if(dp[ind][last] != -1)
        {
            return dp[ind][last];
        }
        
        long long int mini = LONG_MAX;
        for(int i=0;i<3;i++)
        {
            if(i != last)
            {
                mini = min(mini,colors[ind][i] + solve(ind-1,i,colors,dp));
            }
        }
        return dp[ind][last] = mini;
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>>arr(N);
        for(int i=0;i<N;i++)
        {
            arr[i].push_back(r[i]);
            arr[i].push_back(g[i]);
            arr[i].push_back(b[i]);
        }
        
        vector<vector<long long int>>dp(N+1,vector<long long int>(4,-1));
        return solve(N-1,3,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends