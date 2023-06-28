//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int open,int close,int n,string output,vector<string>& ans)
    {
        if(open+close == 2*n)
        {
            ans.push_back(output);
            return;
        }
        
        if(open<n)
        {
            solve(open+1,close,n,output+"(",ans);
        }
        
        if(close<open)
        {
            solve(open,close+1,n,output+")",ans);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        string output = "";
        solve(0,0,n,output,ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends