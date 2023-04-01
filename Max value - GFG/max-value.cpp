//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxVal(int a[], int n) {
      int mini = INT_MAX,maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
          int num = a[i]-i;
          mini = min(mini,num);
          maxi = max(maxi,num);
      }
      
      return abs(maxi-mini);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.maxVal(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends