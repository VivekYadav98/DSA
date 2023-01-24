//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            int n = S.length();
            unordered_map<char,int>m;
            for(int i=0;i<n-1;i++)
            {
                if(S[i] == S[i+1])
                {
                    m[S[i]]++;
                    
                    while(i<n-1 && S[i] == S[i+1])
                    {
                        i++;
                    }
                }
                else
                {
                   m[S[i]]++;
                }
            }
            
            if(S[n-2] != S[n-1])
            {
                m[S[n-1]]++;
            }
            
            int ans = 0;
            for(auto i:m)
            {
                if(i.second == N)
                {
                    ans++;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends