//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        string ans = "";
        int count = 0;
        while(ans.length() <= B.length() + 2*A.length())
        {
            if(ans.find(B) == string::npos)
            {
               ans += A;
               count++;
            }
            else
            {
                break;
            }
        }
       
        if(ans.find(B) == string::npos)
        {
            return -1;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends