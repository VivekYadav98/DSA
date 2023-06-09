//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends

class Solution{
  public:
    void rearrangeArray(int a[], int n) {
        int answer[n];
        sort(a,a+n);
        int i=0,j=0,k=n-1;
        while(j<n && k>=0 && i<n)
        {
            answer[i++] = a[j++];
            
            if(i<n)
            answer[i++] = a[k--];
        }
        
        for(int i=0;i<n;i++)
        {
            a[i] = answer[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        obj.rearrangeArray(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends