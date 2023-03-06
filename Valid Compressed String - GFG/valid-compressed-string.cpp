//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(int num)
    {
        if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5
            || num == 6 || num == 7 || num == 8 ||num == 9)
            {
                return true;
            }
            return false;
    }
    int checkCompressed(string S, string T) {
        int i=0,j=0;
        while(i<S.length() && j<T.length())
        {
            if(S[i] == T[j])
            {
                i++;
                j++;
            }
            else if(check(T[j] - '0'))
            {
                string deletedCount = "";
                    
                while(j<T.length() && check(T[j] - '0'))
                {
                    deletedCount += T[j];
                    j++;
                }
                
                i += stoi(deletedCount);
            }
            else
            {
                return 0;
            }
        }
        
        if(i>S.length() || j>T.length() || i<S.length() || j<T.length())
        {
            return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends