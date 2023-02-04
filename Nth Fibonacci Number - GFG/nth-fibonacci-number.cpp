//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        if(n<=1)return n;
        int mod = 1000000007;
        
        long long int prev2 = 0;
        long long int prev1 = 1;
        long long int curr = 0;
        
        for(int i=2;i<=n;i++)
        {
            curr = (prev1+prev2)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends