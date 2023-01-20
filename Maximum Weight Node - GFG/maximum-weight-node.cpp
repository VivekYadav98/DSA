//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int>weight(N+1,0);
      int ans = 0;
      
      for(int i=0;i<N;i++)
      {
          int x = Edge[i];
          
          if(x != -1)
          {
              weight[x] += i;
          }
      }
      
      int temp = weight[0];
      for(int i=1;i<N;i++)
      {
          if(weight[i] >= temp)
          {
              ans = i;
              temp = weight[i];
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
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends