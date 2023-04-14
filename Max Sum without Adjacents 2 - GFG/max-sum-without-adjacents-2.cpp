//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int solve(int i,int cnt,int n,vector<int>& arr,vector<vector<long long int>>& dp)
  {
      if(i>=n)
      {
          return 0;
      }
      
      if(dp[i][cnt] != -1)
      {
          return dp[i][cnt];
      }
      
      long long int pick = INT_MIN,notPick1 = INT_MIN,notPick2 = INT_MIN;
      if(cnt < 2)
      {
          pick = (long long int)arr[i] + solve(i+1,cnt+1,n,arr,dp);
          notPick1 = solve(i+1,0,n,arr,dp);
      }
      else
      {
          notPick2 = solve(i+1,0,n,arr,dp);
      }
      
      return dp[i][cnt] = max({pick,notPick1,notPick2});
  }
  
  int findMaxSum(vector<int>& a){
      int cnt=0;
      int n = a.size();
      vector<vector<long long int>>dp(n+1,vector<long long int>(3,0));
      
      for(int i=n-1;i>=0;i--)
      {
          for(int cnt=2;cnt>=0;cnt--)
          {
              long long int pick = INT_MIN,notPick1 = INT_MIN,notPick2 = INT_MIN;
              if(cnt < 2)
              {
                  pick = (long long int)a[i] + dp[i+1][cnt+1];
                  notPick1 = dp[i+1][0];
              }
              else
              {
                  notPick2 = dp[i+1][0];
              }
              
             dp[i][cnt] = max({pick,notPick1,notPick2});
          }
      }
      return dp[0][0];
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends