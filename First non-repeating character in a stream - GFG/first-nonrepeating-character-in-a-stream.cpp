//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    unordered_map<char,int>m;
		    queue<char>q;
		    int i=0;
		    string ans = "";
		    
		    while(i<s.length())
		    {
		        if((q.empty() && m[s[i]] < 1) || m[s[i]] < 1)
		        {
		            q.push(s[i]);
		        }
		        
		        m[s[i]]++;
		        
		        if(m[q.front()] == 1)
		        {
		            ans.push_back(q.front());
		        }
		        else
		        {
		            while(!q.empty() && m[q.front()] > 1)
		            {
		                q.pop();
		            }
		            
		            if(q.empty())
		            {
		                ans.push_back('#');
		            }
		            else
		            {
		                ans.push_back(q.front());
		            }
		        }
		        
		        i++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends