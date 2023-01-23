//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        
        while(i<s.length())
        {
            if(!st.empty() && s[i] == st.top())
            {
                st.pop();
                i++;
            }
            else
            {
                st.push(s[i]);
                i++;
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        if(!ans.size())
        {
            return "-1";
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends