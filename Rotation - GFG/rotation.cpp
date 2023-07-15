//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    if(arr[0] <= arr[n-1])
	    {
	        return 0;
	    }
	    
	    int s=0,e=n-1,mid,mini=INT_MAX,ans=-1;
	    
	    while(s<=e)
	    {
	        mid = e+(s-e)/2;
	        
	        if(arr[s] <= arr[mid])
	        {
	            if(arr[s] < mini)
	            {
	                mini = arr[s];
	                ans = s;
	            }
	            s = mid+1;
	        }
	        else
	        {
	            if(arr[mid] < mini)
	            {
	                mini = arr[mid];
	                ans = mid;
	            }
	            e = mid-1;
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
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends