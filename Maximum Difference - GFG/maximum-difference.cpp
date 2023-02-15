//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void solve(int A[],int n,vector<int>& ls)
    {
          stack<int>s;
          ls.push_back(0);
          s.push(A[0]);
          int i=1;
          
          while(i<n)
          {
             if(!s.empty() && s.top() < A[i])
             {
                 ls.push_back(s.top());
                 s.push(A[i]);
                 i++;
             }
             else if(!s.empty())
             {
                s.pop(); 
             }
             else
             {
                 ls.push_back(0);
                 s.push(A[i]);
                 i++;
             }
          }
    }
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      vector<int>ls;
      vector<int>rs;
      
      solve(A,n,ls);
      
      reverse(A,A+n);
      solve(A,n,rs);
      
     reverse(rs.begin(),rs.end());
      
      int ans = INT_MIN;
      for(int i=0;i<n;i++)
      {
          ans = max(ans , abs(ls[i]-rs[i]));
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
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends