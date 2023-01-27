//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod = 1000000007;
	bool isValid(string s)
	{
	    if(s[0] == '0' || stoi(s) > 26)
	    {
	        return false;
	    }
	    return true;
	}
	
    // 	int solve(string s,int& ans,int index)
    // 	{
    // 	    if(index >= s.size())
    // 	    {
    // 	        return 1;
    // 	    }
    	    
    // 	    if(isValid(s.substr(index,1)))
	   //     {
	   //         ans += solve(s,ans,index+1);
	   //     }
	        
	   //     if((index<s.size()-1) && isValid(s.substr(index,2)))
	   //     {
	   //         ans += solve(s,ans,index+2);
	   //     }
    	
    // 	    return 0;
    // 	}
    
    	int solve(string s,int index,vector<int>& dp)
    	{
    	    if(index >= s.size())
    	    {
    	        return 1;
    	    }
    	    
    	    if(dp[index] != -1)
    	    {
    	        return dp[index];
    	    }
    	    
    	    int ans = 0;
    	    if(isValid(s.substr(index,1)))
	        {
	            ans += solve(s,index+1,(dp))%mod;
	        }
	        
	        if((index<s.size()-1) && isValid(s.substr(index,2)))
	        {
	            ans += solve(s,index+2,dp)%mod;
	        }
    	
    	    return dp[index] = ans%mod;
    	}
	
		int CountWays(string str){
		    int n = str.size();
		    vector<int>dp(n+1,-1);
		   return solve(str,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends