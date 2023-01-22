class Solution {
public:
    int solve(string s,string t,int m,int n,vector<vector<int>>& dp)
  {
      if(m == 0)
      {
          return n;
      }
      
      if(n == 0)
      {
          return m;
      }
      
      if(dp[m][n] != -1)
      {
          return dp[m][n];
      }
      
      if(s[m-1] == t[n-1])
      {
          return dp[m][n] = solve(s,t,m-1,n-1,dp);
      }
      else 
      {
          return dp[m][n] = 1 + min(solve(s,t,m,n-1,dp) ,
          min(solve(s,t,m-1,n,dp) , solve(s,t,m-1,n-1,dp)));
      }
  }
  
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m,n,dp);  
    }
};