//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans = arr[0];
        for(int i=1;i<N;i++)
        {
            string temp = "";
            string s = arr[i];
            
            for(int j=0;j<s.length() && j<ans.length();j++)
            {
                if(s[j] == ans[j])
                {
                    temp += s[j];
                }
                else
                {
                    break;
                }
            }
            
            if(temp.size()<ans.size())
            {
                ans = temp;
            }
        }
        if(ans.size() == 0)
        {
            return "-1";
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
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends