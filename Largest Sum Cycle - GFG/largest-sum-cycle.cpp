//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int ans = -1;
  void dfs(vector<int>& Edge,vector<bool>& vis,vector<bool>& pathVis,int node)
  {
      vis[node] = true;
      pathVis[node] = true;
      
      int it = Edge[node];
      if(!vis[it] && Edge[it] != -1)
      {
          dfs(Edge,vis,pathVis,it);
      }
      else if(vis[it] == true && pathVis[it] == true)
      {
          int sum = it;
          int x = it;
          while(Edge[it] != x)
          {
              sum += Edge[it];
              it = Edge[it];
          }
          ans = max(ans,sum);
      }
      
      pathVis[node] = false;
  }
  
  long long largestSumCycle(int N, vector<int> Edge)
  {
    vector<bool>vis(N,false);
    vector<bool>pathVis(N,false);
    int sum = 0;
    
    for(int i=0;i<N;i++)
    {
        if(!vis[i] && Edge[i] != -1)
        {
            dfs(Edge,vis,pathVis,i);
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends