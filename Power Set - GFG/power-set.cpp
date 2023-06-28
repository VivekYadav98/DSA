//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int i,string& s,string& output,vector<string>& ans)
	    {
	        if(i>=s.length())
	        {
	            if(output.size())
	            {
	              ans.push_back(output);
	            }
	            return;
	        }
	        
	        output.push_back(s[i]);
	        solve(i+1,s,output,ans);
	        output.pop_back();
	        
	        solve(i+1,s,output,ans);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    string output = "";
		    solve(0,s,output,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends