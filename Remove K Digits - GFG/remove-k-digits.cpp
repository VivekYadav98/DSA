//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<int>st;
        int i=0;
        
        while(i<S.length())
        {
            if(st.empty() && S[i] == '0')
            {
                i++;
                continue;
            }
            
            if(st.empty() && S[i] != '0')
            {
                st.push(S[i]-'0');
            }
            else
            {
                while(!st.empty() && st.top() > S[i]-'0' && K>0)
                {
                    st.pop();
                    K--;
                }
                st.push(S[i]-'0');
            }
            i++;
        }
        
        while(K>0)
        {
            st.pop();
            K--;
        }
        
        string ans = "";
        while(!st.empty())
        {
            char ch = st.top()+'0';
            ans = ch + ans;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        while(ans[ans.size()-1] == '0')
        {
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.empty())
        {
            return "0";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends