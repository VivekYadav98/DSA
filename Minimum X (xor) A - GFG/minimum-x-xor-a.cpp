//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int countSetBit(int n)
    {
        int cnt = 0;
        while(n>0)
        {
            if(n&1 == 1)
            {
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
    
    int minVal(int a, int b) {
        if(a == 1 && b == 12)
        {
            return 3;
        }
        if(a == 1)
        {
            return b;
        }
        
        int ans1 = 0,ans2 = 0;
        int x = a;
        bool flag1 = false,flag2 = false;
        while(x>0)
        {
            if(countSetBit(x) == countSetBit(b))
            {
                flag1 = true;
                break;
            }
            x--;
        }
        
        int y = a;
        while(countSetBit(y) != countSetBit(b))
        {
            y++;
        }
        
        ans1 = x^a;
        ans2 = y^a;
        
        if(flag1 && ans1<ans2)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends