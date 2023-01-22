//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int prefix[n];
        int ans = 0;
        prefix[0] = A[0];
        
        for(int i=1;i<n;i++)
        {
            prefix[i] = A[i] + prefix[i-1];
        }
        
         map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(m.find(prefix[i]) != m.end())
            {
                int x = i-m[prefix[i]];
                ans = max(ans,x);
            }
            else if(prefix[i] == 0)
            {
                ans = max(ans,i+1);
            }
            else
            {
                m[prefix[i]] = i;
            }
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends