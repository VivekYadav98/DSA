//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        int x = max({a,b,c});
        int y=0;
        if(x == a)
        {
            y = b+c;
        }
        else if(x == b)
        {
            y = a+c;
        }
        else
        {
            y = a+b;
        }
        
        if(((y != 0) && (x/y >= 2 && x%y >= 3)) || ((y != 0) && (x/y > 2)))
        {
            return -1;
        }
        else if(y == 0)
        {
            return -1;
        }
        return a+b+c;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends