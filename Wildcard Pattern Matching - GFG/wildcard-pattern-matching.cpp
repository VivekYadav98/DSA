//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
     bool solve(int i,int j,string& pattern,string& str,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(j==0 && i>0)
        {
            for(int ind=1;ind<=i;ind++)
            {
                if(pattern[ind-1] != '*')return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
        {
            return solve(i-1,j-1,pattern,str,dp);
        }
        if(pattern[i-1] == '*')
        {
            return solve(i-1,j,pattern,str,dp) | solve(i,j-1,pattern,str,dp);
        }
        return false;
    }

    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = false;
        }

        for(int i=1;i<=n;i++)
        {
            bool flag = true;
            for(int ind=1;ind<=i;ind++)
            {
                if(pattern[ind-1] != '*')
                {
                    flag = false;
                }
            }
            dp[i][0] = flag;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends