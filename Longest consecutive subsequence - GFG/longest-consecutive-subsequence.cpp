//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int mini = INT_MAX;
      int maxi = INT_MIN;
      int ans = 1;
      unordered_map<int,int>m;
      
      for(int i=0;i<N;i++)
      {
          mini = min(mini,arr[i]);
          maxi = max(maxi,arr[i]);
          m[arr[i]]++;
      }
      
      int count = 1;
      for(int i=mini;i<maxi;i++)
      {
          if(m.find(i) != m.end() && m.find(i+1) != m.end())
          {
              count++;
          }
          else
          {
              ans = max(ans,count);
              count = 1;
          }
      }
      ans = max(ans,count);
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends