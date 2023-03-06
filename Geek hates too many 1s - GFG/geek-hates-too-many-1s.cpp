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
            int a = pow(2,i);
            if((n&a) == a)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            
            if(cnt == 3)
            {
                int num = 4294967295 - a;
                n = n&num;
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