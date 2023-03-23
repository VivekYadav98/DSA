//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        vector<int>vis(26,0);
        for(int i=0;i<S.length();i++)
        {
            vis[S[i]-'a']++;
        }
        
        int i=0;
        int j = 0;
        bool flag = true;
        while(i<S.size() && i>=0)
        {
            if(flag == true && vis[S[i]-'a'] > 1)
            {
                flag = false;
                vis[S[i]-'a']--;
                S.erase(i,1);
                i = S.size();
            }
            else if(flag == false && vis[S[i]-'a'] > 1)
            {
                flag = true;
                vis[S[i]-'a']--;
                S.erase(i,1);
                i = -1;
            }
            
            if(flag == true)
            {
                i++;
            }
            else
            {
                i--;
            }
            
        }
        
        if(flag == false)
        {
            reverse(S.begin(),S.end());
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends