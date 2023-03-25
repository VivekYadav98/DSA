//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
     if(s.size()%2 != 0)
     {
         return -1;
     }
     
     stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(st.empty())
            {
                st.push(ch);
            }
            else
            {
                if(st.top() == '{' && ch == '}')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        
        int ans = 0;
        int open=0,close=0;
        while(!st.empty())
        {
            if(st.top() == '{')
            {
                open++;
            }
            else
            {
                close++;
            }
            st.pop();
        }
        
        if(open == 0)
        {
            return close/2;
        }
        else if(close == 0)
        {
            return open/2;
        }
        
        if(open%2 == 0)
        {
            ans += (open/2) + (close/2);
        }
        else
        {
            ans += (open/2) + (close/2) + 2;
        }
        return ans;
}