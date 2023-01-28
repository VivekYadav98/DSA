//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int ans = 0;
        int s=0,e=n-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
           
            if(mid%2 != 0 && arr[mid] == arr[mid+1])
            {
                e = mid-1;
            }
            else if(mid%2 != 0 && arr[mid] == arr[mid-1])
            {
                s = mid+1;
            }
            else if(mid%2 == 0 && arr[mid] == arr[mid+1])
            {
                s = mid+1;
            }
            else if(mid%2 == 0 && arr[mid] == arr[mid-1])
            {
                e = mid-1;
            }
            else
            {
                return arr[mid];
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends