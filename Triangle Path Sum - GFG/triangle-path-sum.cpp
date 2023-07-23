//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i == n-1)
        {
            return triangle[i][j];
        }
        
        if(i>=n)
        {
            return 1e8;
        }
        
        int m = triangle[i].size();
        if(j>=m)
        {
            return 1e8;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int ans1 = triangle[i][j] + solve(i+1,j,n,triangle,dp);
        int ans2 = triangle[i][j] + solve(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(ans1,ans2);
    }
    
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends