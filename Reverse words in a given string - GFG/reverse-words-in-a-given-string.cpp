//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int i=S.length()-1;
        string temp = "",ans="";
        while(i>=0)
        {
            if(S[i] != '.')
            {
                temp += S[i];
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += '.';
                temp = "";
            }
            i--;
        }
        
        reverse(temp.begin(),temp.end());
        ans += temp;
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends