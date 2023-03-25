//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool>vis(leaves+1,true);
        vis[0] = false;
        for(int i=0;i<N;i++)
        {
            int val = frogs[i];
            if(vis[val])
            {
                vis[val] = false;
                for(int j=2*val;j<=leaves;j+=val)
                {
                    vis[j] = false;
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=leaves;i++)
        {
            if(vis[i])
            {
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends