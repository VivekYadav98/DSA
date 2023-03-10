//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool solve(int i,int nums[],vector<int>& dp,int n)
    {
        if(i >= n-1)
        {
            return true;
        }

        
        for(int jump=1;jump<=nums[i];jump++)
        {
            if(solve(i+jump , nums,dp,n))
            {
                return true;
            }
        }
        return false;
    }
    int canReach(int A[], int N) {
        vector<int>dp(N+1,-1);
        return solve(0,A,dp,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends