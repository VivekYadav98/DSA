//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            vector<int>arr(26,0);
            for(int j=i;j<s.length();j++)
            {
                int mini = INT_MAX,maxi=INT_MIN;
                arr[s[j]-'a']++;

                
                for(int i=0;i<26;i++)
                {
                    if(arr[i] != 0)
                    {
                       maxi = max(maxi,arr[i]);
                       mini = min(mini,arr[i]);
                    }
                }
                
                ans += maxi-mini;
            }
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends