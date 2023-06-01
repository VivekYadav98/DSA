//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int>prime;
    void precompute(){
        vector<bool>isPrime(1e6+2,true);
        for(int i=2;i<=1e6+1;i++)
        {
            if(isPrime[i])
            {
                prime.push_back(i);
            
                for(int j=2*i;j<=1e6+1;j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    void dfs(int node,int& cnt,vector<vector<int>> &g,vector<bool>& vis)
    {
        cnt++;
        vis[node] = true;
        
        for(auto it:g[node])
        {
            if(!vis[it])
            {
                dfs(it,cnt,g,vis);
            }
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        int maxi = 0;
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++)
        {
            int cnt = 0;
            if(!vis[i])
            {
               dfs(i,cnt,g,vis);
            }
            
            maxi = max(maxi,cnt);
        }
    
        if(maxi == 1)
        {
            return -1;
        }
        return prime[maxi-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends