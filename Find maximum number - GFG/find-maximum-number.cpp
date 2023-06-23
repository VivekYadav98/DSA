//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string findMax(string N) {
        vector<int>freq(10,0);
        for(int i=0;i<N.length();i++)
        {
            int ind = N[i]-'0';
            freq[ind]++;
        }
        
        string ans = "";
        for(int i=9;i>=0;i--)
        {
            int cnt = freq[i];
            
            while(cnt--)
            {
                ans += i+'0';
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
        string N;
        
        cin>>N;

        Solution ob;
        cout << ob.findMax(N) << endl;
    }
    return 0;
}
// } Driver Code Ends