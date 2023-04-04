//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());
        int maxi = arr[N-1];
        vector<bool>special(maxi+1,false);
        
        for(int i=0;i<N;i++)
        {
            int val = arr[i];
            if(special[val] == false)
            {
                if(i+1 < N && arr[i] == arr[i+1])
                {
                    special[val] = true;
                }
                
               for(int j=2*val;j<=maxi;j=j+val)
                {
                    special[j] = true;
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(special[arr[i]] == true)
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends