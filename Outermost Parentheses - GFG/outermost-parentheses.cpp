//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        stack<char>st;
        int i=0;
        string ans = "";
        
        while(i<s.length())
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i] == '(')
            {
                ans += s[i];
                st.push(s[i]);
            }
            else
            {
                if(s[i] == ')' && st.size() > 1)
                {
                    ans += s[i];
                    st.pop();
                }
                else
                {
                    st.pop();
                }
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends