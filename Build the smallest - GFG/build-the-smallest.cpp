//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string S, int K)
{
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
}