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
          if((n&1) == 1)
          {
              sum++;
          }
          n = n>>1;
      }
      return sum;
  }
    
 
    int minVal(int num1, int num2) {
        long long int setBits1 = check(num1);
        long long int setBits2 = check(num2);
        long long int x = num1;
        if(setBits1 == setBits2)
        {
           return x; 
        }
        
        long long int setBitsx = check(x);
        if(setBitsx < setBits2)
        {
            while(setBitsx<setBits2)
            {
                x = x|(x+1);
                setBitsx = check(x);
            }
        }
        else
        {
            while(setBitsx>setBits2)
            {
                    x = x&(x-1);
                setBitsx = check(x);
            }
        }
        return x;
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