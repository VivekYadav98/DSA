//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,int cnt)
    {
        if(cnt == 0)
        {
            return true;
        }
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,cnt-1))
                {
                    return true;
                }
            }
        }
        
        vis[node] = false;
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<vector<int>>adj(N);
        for(auto it:Edges)
        {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        
        vector<bool>vis(N,false);
        for(int i=0;i<N;i++)
        {
            if(dfs(i,adj,vis,N-1))
            {
                return true;
            }
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends