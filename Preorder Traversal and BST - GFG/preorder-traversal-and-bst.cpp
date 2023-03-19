//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ind = 0;
    void solve(int mini,int maxi,int arr[],int n)
    {
        if(ind >= n || arr[ind]<mini || arr[ind]>maxi)
        {
            return;
        }
        
        int num = arr[ind++];
        solve(mini,num,arr,n);
        solve(num,maxi,arr,n);
    }
    int canRepresentBST(int arr[], int N) {
        solve(INT_MIN,INT_MAX,arr,N);
        if(ind>=N)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends