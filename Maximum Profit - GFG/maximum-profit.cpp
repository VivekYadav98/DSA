//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>>next(2,vector<int>(K+1,0));
        vector<vector<int>>curr(2,vector<int>(K+1,0));

        for(int ind=N-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=K;cap++)
                {
                    int profit = 0;
                    if(buy)
                    {
                        profit = max(-A[ind] + next[0][cap] , 0 + next[1][cap]);
                    }
                    else
                    {
                        profit = max(A[ind] + next[1][cap-1] , 0 + next[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
                next = curr;
            }
        }

        return next[1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends