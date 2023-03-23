//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
       vector<int> rank,parent;
       DisjointSet(int n)
       {
           parent.resize(n+1);
           rank.resize(n+1,0);
           for(int i=0;i<=n;i++)
           {
               parent[i] = i;
           }
       }

       int findUpar(int node)
       {
           if(node == parent[node])
           {
               return node;
           }
           return findUpar(parent[node]);
       }

       void unionByRank(int u,int v)
       {
           int ulp_u = findUpar(u);
           int ulp_v = findUpar(v);

           if(ulp_u == ulp_v)
           {
               return;
           }

           if(rank[ulp_u] < rank[ulp_v])
           {
               parent[ulp_u] = ulp_v;
           }
           else if(rank[ulp_v] < rank[ulp_u])
           {
               parent[ulp_v] = ulp_u;
           }
           else
           {
               parent[ulp_u] = ulp_v;
               rank[ulp_v]++;
           }
       }
};


class Solution{
    public:
        int minimumConnections(vector<vector<int>> &c,int n)
        {
            DisjointSet ds(n);
            int cnt = 0;
            int connection=0;
    
            for(int i=0;i<c.size();i++)
            {
                int u = c[i][0];
                int v = c[i][1];
    
                if(ds.findUpar(u) == ds.findUpar(v))
                {
                    cnt++;
                }
                else
                {
                    connection++;
                    ds.unionByRank(u,v);
                }
            }
    
            int total = n-1;
            int required = total-connection;
    
            if(cnt >= required)
            {
                return required;
            }
            return -1;
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
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends