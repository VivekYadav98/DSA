//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) {
        int l=0,h=N-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(A[mid] == key)
            {
                return true;
            }
            
            if((A[l] == A[mid]) && (A[h] == A[mid]))
            {
                l++;
                h--;
            }
            else if(A[mid] >= A[l])
            {
                if(key>=A[l] && key<A[mid])
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(key>A[mid] && key<=A[h])
                {
                    l = mid+1;
                }
                else
                {
                    h = mid-1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends