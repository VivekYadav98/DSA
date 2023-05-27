//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        vector<int>arr(32,0);
        long long num = X;
        int ind = 31;
        
        while(num>0)
        {
            int a = num%2;
            arr[ind] = a;
            num /= 2;
            ind--;
        }
        
        reverse(arr.begin(),arr.end());
        long long ans = 0;
        for(int i=31;i>=0;i--)
        {
            ans += arr[i]*pow(2,31-i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends