//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        int cnt = 0;
        int i = 31;
        while(i>=0)
        {
            int a = 1<<i;
            if((n&a) > 0)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            
            if(cnt == 3)
            {
                n-=(1<<i);
                cnt = 0;
            }
            i--;
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends