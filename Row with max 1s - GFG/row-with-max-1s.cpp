//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1;
	    int cnt = 0;
	    for(int i=0;i<n;i++)
	    {
	        int temp = 0;
	        if(arr[i][m-1] == 0)
	        {
	            continue;
	        }
	        
	        for(int j=0;j<m;j++)
	        {
	           if(arr[i][j] == 1)
	           {
	               temp += (m-j);
	               break;
	           }
	        }
	        
	        if(temp > cnt)
	        {
	            cnt = temp;
	            ans = i;
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
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends