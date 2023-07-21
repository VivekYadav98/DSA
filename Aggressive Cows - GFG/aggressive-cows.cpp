//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int dist,vector<int>& arr,int k)
    {
        int prev = 0;
        for(int i=1;i<arr.size() && k>1;i++)
        {
            if(arr[i]-arr[prev] >= dist)
            {
                k--;
                prev = i;
            }
        }
        
        if(k == 1)
        {
            return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int ans = 0;
        
        int low=1,high=1e9,mid;
        
        while(low<=high)
        {
            mid = high+(low-high)/2;
            
            if(isPossible(mid,stalls,k))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends