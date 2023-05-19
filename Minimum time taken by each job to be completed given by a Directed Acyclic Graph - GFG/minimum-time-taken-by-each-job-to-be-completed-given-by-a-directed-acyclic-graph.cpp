//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int>ans(n,0);
            vector<int>indegree(n,0);
            vector<vector<int>>adj(n);
            
           for(int i=0;i<edges.size();i++)
           {
               int u = edges[i][0]-1;
               int v = edges[i][1]-1;
               
               adj[u].push_back(v);
           }
            
            for(int i=0;i<n;i++)
            {
                for(auto it:adj[i])
                {
                    indegree[it]++;
                }
            }
            
            queue<int>q;
            for(int i=0;i<n;i++)
            {
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
            
            int cnt = 1;
            while(!q.empty())
            {
                int size = q.size();
                for(int i=0;i<size;i++)
                {
                    int node = q.front();
                    q.pop();
                    ans[node] = cnt;
                    
                    for(auto it:adj[node])
                    {
                        indegree[it]--;
                        
                        if(indegree[it] == 0)
                        {
                            q.push(it);
                        }
                    }
                }
                cnt++;
            }
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
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends