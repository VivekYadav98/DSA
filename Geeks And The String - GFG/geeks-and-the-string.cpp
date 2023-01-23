//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
         string res = "";
        for(int i=0;i<s.length();i++)
        {
            if(i<s.length()-1 && s[i] == s[i+1])
            {
                i++;
            }
            else
            {
                res += s[i];
            }
        }
        
        if(s.length() == res.length())
        {
            return s;
        }
        else if(res.length() == 0)
        {
            return "-1";
        }
        else
        {
            return removePair(res);
        }
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