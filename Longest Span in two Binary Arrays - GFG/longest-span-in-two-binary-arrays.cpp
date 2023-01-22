//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        int arr[n];
           for(int i=0;i<n;i++)
           {
               arr[i] = arr1[i]-arr2[i];
           }
           
           int ans = 0;
           unordered_map<int,int>m;
           int prefixSum = 0;
           
           for(int i=0;i<n;i++)
           {
               prefixSum += arr[i];
               
               if(m.find(prefixSum) == m.end())
               {
                   m[prefixSum] = i;
               }
               
               if(prefixSum == 0)
               {
                   ans = max(ans,i+1);
               }
               
               ans = max(ans,i-m[prefixSum]);
           }
           return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends