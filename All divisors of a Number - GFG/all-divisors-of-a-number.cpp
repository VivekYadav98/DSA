//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        int i;
        unordered_set<int>s;
        for( i=1;i*i<n;i++)
        {
            if(n%i == 0)
            {
                s.insert(i);
                cout<<i<<" ";
            }
        }
        
        for(;i>=1;i--)
        {
            if(n%i == 0 && s.find(n/i) == s.end())
            {
                cout<<n/i<<" ";
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends