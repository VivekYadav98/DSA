//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int p,vector<vector<int>>&G,vector<int>& match,vector<bool>& vis)
    {
        for(int j=0;j<G[0].size();j++)
        {
            if(G[p][j] && !vis[j])
            {
                vis[j] = 1;
                if(match[j] == -1 || solve(match[j],G,match,vis))
                {
                    match[j] = p;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    int p = G.size();
	    int j = G[0].size();
	    vector<int>match(j,-1);
	    int ans = 0;
	    for(int i=0;i<p;i++)
	    {
	        vector<bool>vis(j,false);
	        if(solve(i,G,match,vis))
	        {
	            ans++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends