//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        
        while(i<s.length())
        {
            if(!st.empty() && ((s[i] == '1' && st.top() == '2') || (s[i] == '2' && st.top() == '1')
            || (s[i] == '3' && st.top() == '4') || (s[i] == '4' && st.top() == '3') 
            || (s[i] == '5' && st.top() == '6') || (s[i] == '6' && st.top() == '5') ||
            (s[i] == '7' && st.top() == '8') ||
            (s[i] == '8' && st.top() == '7') || (s[i] == '0' && st.top() == '9') ||
            (s[i] == '9' && st.top() == '0')))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        
       
        return st.size();
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends