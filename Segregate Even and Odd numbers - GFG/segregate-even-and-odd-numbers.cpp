//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    sort(arr,arr+n);
	    vector<int>even,odd;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]%2)
	        {
	            odd.push_back(arr[i]);
	        }
	        else
	        {
	            even.push_back(arr[i]);
	        }
	    }
	    
	    int i=0,k=0;
	    while(i<even.size())
	    {
	        arr[k++] = even[i];
	        i++;
	    }
	    i=0;
	    while(i<odd.size())
	    {
	        arr[k++] = odd[i];
	        i++;
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
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends