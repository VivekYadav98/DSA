//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
         int n = s.length();
        unordered_map<char,pair<int,int>>m;
        m['I'] = {1,0};
        m['V'] = {5,1};
        m['X'] = {10,2};
        m['L'] = {50,3};
        m['C'] = {100,4};
        m['D'] = {500,5};
        m['M'] = {1000,6};
        
        int ans = m[s[n-1]].first;
        for(int i=s.length()-2;i>=0;i--)
        {
            if(m[s[i]].second < m[s[i+1]].second)
            {
                ans -= m[s[i]].first;
            }
            else
            {
                ans += m[s[i]].first;
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends