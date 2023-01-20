//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n = S.length();
        int start = 0,end=1;
        
        for(int i=0;i<n;i++)
        {
            // EVEN LENGTH
            int low = i-1;
            int high = i;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
                if(high-low+1 > end)
                {
                    end = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
            
        //   ODD LENGTH
            low = i-1;
            high = i+1;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
                if(high-low+1 > end)
                {
                    end = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
        }
        
        return S.substr(start,end);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends