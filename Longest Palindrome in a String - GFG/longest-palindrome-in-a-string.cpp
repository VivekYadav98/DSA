//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    string longestPalin (string S) {
        string ans = "";
        int n = S.length();
        int start = 0,end=0;
        
        for(int i=1;i<S.length();i++)
        {
            // Even Length
            int low = i-1;
            int high = i;
            
            int temp1=0,temp2=0;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
                temp1 = low;
                temp2 = high;
                low--;
                high++;
            }
            
            if((temp2-temp1+1) > (end-start+1))
            {
                start = temp1;
                end = temp2;
            }
            
            // Odd length
            low = i;
            high = i;
            
            temp1=0,temp2=0;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
                temp1 = low;
                temp2 = high;
                low--;
                high++;
            }
            
            if((temp2-temp1+1) > (end-start+1))
            {
                start = temp1;
                end = temp2;
            }
            
            // cout<<start<<" "<<end;
        }
        
        
        return S.substr(start,end-start+1);
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