//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	int indFloor=-1,indCeil=-1;
    int s=0,e=n-1,mid;
    
    while(s<=e)
    {
        mid = s+(e-s)/2;
        
        if(arr[mid] == x)
        {
            indFloor = mid;
            e = mid-1;
        }
        else if(arr[mid] < x)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    
    s=0,e=n-1,mid;
    
    while(s<=e)
    {
        mid = s+(e-s)/2;
        
        if(arr[mid] == x)
        {
            indCeil = mid;
            s = mid+1;
        }
        else if(arr[mid] < x)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    
    if(indFloor == -1)
    {
        return 0;
    }
    return indCeil-indFloor+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends