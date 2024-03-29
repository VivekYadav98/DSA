//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int n = bt.size();
        vector<int>ct(n,0),wt(n,0);
        
        ct[0] = bt[0];
        for(int i=1;i<n;i++)
        {
            ct[i] = ct[i-1] + bt[i];
        }
        
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            wt[i] = ct[i]-bt[i];
            sum += wt[i];
        }
        
        int ans = sum/n;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends