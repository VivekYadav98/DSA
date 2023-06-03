//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    int pos[n];
	    int neg[n];
	    int posInd = 0,negInd=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] >= 0)
	        {
	            pos[posInd++] = arr[i];
	        }
	        else
	        {
	            neg[negInd++] = arr[i];
	        }
	    }
	    
	    int i=0,j=0,k=0;
	    while(i<posInd && j<negInd)
	    {
	        arr[k++] = pos[i++];
	        arr[k++] = neg[j++];
	    }
	    
	    while(i<posInd)
	    {
	        arr[k++] = pos[i++];
	    }
	    
	    while(j<negInd)
	    {
	        arr[k++] = neg[j++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends