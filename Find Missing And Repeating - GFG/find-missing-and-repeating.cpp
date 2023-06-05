//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        for(int i=0;i<n;i++)
        {
            int num = arr[i]%(n+1);
            
            arr[num-1] += (n+1);
        }
        
        int n1=0,n2=0;
        for(int i=0;i<n;i++)
        {
            arr[i] /= (n+1);
            
            if(arr[i] == 2)
            {
                n1 = i+1;
            }
            if(arr[i] == 0)
            {
                n2 = i+1;
            }
        }
        
        return {n1,n2};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends