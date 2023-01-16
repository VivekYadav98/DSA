//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
       vector<long long>ans;
       stack<long long>s;
       s.push(-1);
       int i=n-1;
       
       while(!s.empty() && i>=0)
       {
           if(s.top()>arr[i] || s.size() == 1)
           {
               ans.push_back(s.top());
               s.push(arr[i]);
               i--;
           }
           else if(s.top()<arr[i])
           {
               s.pop();
           }
       }
       reverse(ans.begin(),ans.end());
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends