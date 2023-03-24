//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        int cnt = 0;
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(')
            {
                st.push(s[i]);
            }
            else 
            {
                if(ch == ')')
                {
                    bool flag = true;
                    
                    while(st.top() != '(')
                    {
                        char ch = st.top();
                        st.pop();
                        
                        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
                        {
                            flag = false;
                        }
                    }
                    
                    if(flag == true)
                    {
                        return true;
                    }
                    
                    st.pop();
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends