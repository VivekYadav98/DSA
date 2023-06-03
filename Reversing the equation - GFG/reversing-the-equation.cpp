//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        string ans = "";
        int i = s.length();
        while(i>=0)
        {
            string temp = "";
            if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
            {
                while(i>=0 && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
                {
                    temp += s[i];
                    i--;
                }
            }
            else
            {
                ans += s[i];
                i--;
            }
            
            reverse(temp.begin(),temp.end());
            ans += temp;
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
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends