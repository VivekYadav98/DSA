//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int isTriangular(int N){
        int i=1;
        while(i*(i+1) <= 2*N)
        {
            if(i*(i+1) == 2*N)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.isTriangular(N)<<"\n";
    }
}
// } Driver Code Ends