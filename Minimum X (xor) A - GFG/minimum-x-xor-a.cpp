//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int check(int n)
  {
      int sum = 0;
      while(n>0)
      {
          if(n&1 == 1)
          {
              sum++;
          }
          n /= 2;
      }
      return sum;
  }
  
    int minVal(int a, int b) {
        int setbitsB = check(b);
        int x = a;
        
        int setbitsX = check(x);
        if(setbitsB ==   setbitsX)
        {
            return x;
        }
        
        int y = x;
        int num1=0,num2=0;
        
        while(true)
        {
            x--;
            num1 = x^a;
            y++;
            num2 = y^a;
            
            if(check(b) == check(y) && num2<=num1)
            {
                return y;
            }
            else if(check(b) == check(x) && num1<=num2)
            {
                return x;
            }
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