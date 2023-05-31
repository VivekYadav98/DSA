//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        int ans = INT_MIN;
        int freq = INT_MAX;
        for(auto i:m)
        {
            if(i.second < freq)
            {
                ans = i.first;
                freq = i.second;
            }
            else if(i.second == freq)
            {
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends