//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
        diff[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1)
            {
                return effort;
            }
            
            for(int i=0;i<4;i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newEffort = max(abs(heights[newr][newc] - heights[r][c]),effort);
                    if(newEffort < diff[newr][newc])
                    {
                        diff[newr][newc] = newEffort;
                        pq.push({diff[newr][newc],{newr,newc}});
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends