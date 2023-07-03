//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0,i=0,j=0;
        long long product = 1;
        
        while(j<n)
        {
            product = product*a[j];
            
            if(product < k)
            {
                ans += j-i+1;
                j++;
            }
            else
            {
                while(product >= k && i<j)
                {
                    product /= a[i];
                    i++;
                }
                
                if(product<k)
                {
                   ans += j-i+1;
                }
                j++;
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
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends