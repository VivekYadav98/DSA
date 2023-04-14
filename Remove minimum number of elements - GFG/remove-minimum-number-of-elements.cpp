//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
        unordered_map<int,int>mp1,mp2;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            mp1[a[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            mp2[b[i]]++;
        }
        
        for(auto i:mp1)
        {
            if(mp2.find(i.first) != mp2.end())
            {
                ans += min(mp1[i.first] , mp2[i.first]);
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
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < m; i++) cin >> b[i];
        Solution obj;
        cout << obj.minRemove(a, b, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends