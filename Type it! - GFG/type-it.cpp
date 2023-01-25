//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        if(s.length() == 1)
        {
            return 1;
        }
        
       int ans = 0;
       int j=1;
       
       while(j<s.length())
       {
           int count = 0;
           int k = j;
           for(int i=0;i<j;i++)
               {
                   if(s[k] == s[i])
                   {
                       count++;
                       k++;
                       ans = max(ans,count);
                   }
                   else
                   {
                       i=j;
                   }
               }
               j++;
       }
       
       int n = s.length();
       if(ans == 0)
       {
           return n;
       }
       
       return n-ans+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends