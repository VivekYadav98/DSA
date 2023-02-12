//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void solve(string s,string t,int i,int j,string temp,vector<string>& ans,set<string>& st,
    vector<vector<int>>& dp,unordered_set<string>& mp)
    {
        if(i==0 || j==0)
        {
            reverse(temp.begin(),temp.end());
            if(st.find(temp) == st.end())
            {
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        
        string key = "";
        key += to_string(i);
        key += to_string(j);
        key += temp;
        if(mp.find(key) != mp.end())
        {
            return;
        }
        mp.insert(key);
        
        if(s[i-1] == t[j-1])
        {
            solve(s,t,i-1,j-1,temp+s[i-1],ans,st,dp,mp);
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            solve(s,t,i-1,j,temp,ans,st,dp,mp);
        }
        else if(dp[i][j-1] > dp[i-1][j])
        {
            solve(s,t,i,j-1,temp,ans,st,dp,mp);
        }
        else
        {
            solve(s,t,i-1,j,temp,ans,st,dp,mp);
            solve(s,t,i,j-1,temp,ans,st,dp,mp);
        }
    }
	    
	vector<string> all_longest_common_subsequences(string s, string t)
	{
	    int n = s.length();
	    int m = t.length();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        string temp = "";
        vector<string>ans;
        set<string>st;
        unordered_set<string>mp;
        solve(s,t,n,m,temp,ans,st,dp,mp);
        sort(ans.begin(),ans.end());
        return ans;
	}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends