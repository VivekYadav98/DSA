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
     
        if(N == 0)
        {
            return 0;
        }

      unordered_map<int,int>m;
      
      for(int i=0;i<N;i++)
      {
          m[arr[i]]++;
      }

      int curr = 1,ans = 1;
      for(int i=0;i<N;i++)
      {
          if(m.find(arr[i]-1) == m.end())
          {
              curr = 1;
              while(m.find(arr[i]+curr) != m.end())
              {
                  curr++;
              }
              ans = max(ans,curr);
          }
      }
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